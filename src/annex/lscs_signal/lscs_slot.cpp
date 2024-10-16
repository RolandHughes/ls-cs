/***********************************************************************
*
* Copyright (c) 2016-2024 Barbara Geller
* Copyright (c) 2016-2024 Ansel Sermersheim
*
* This file is part of LsCsSignal.
*
* LsCsSignal is free software, released under the BSD 2-Clause license.
* For license details refer to LICENSE provided with this project.
*
* LsCsSignal is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#include "lscs_signal.h"
#include "lscs_slot.h"

LsCsSignal::SlotBase::SlotBase()
{
}

LsCsSignal::SlotBase::SlotBase( const SlotBase & )
{
}

LsCsSignal::SlotBase::~SlotBase()
{
    try
    {
        // clean up possible sender connections
        auto receiverListHandle = m_possibleSenders.lock_read();

        for ( auto &sender : *receiverListHandle )
        {
            auto senderListHandle = sender->m_connectList.lock_write();

            auto iter = senderListHandle->begin();

            while ( iter != senderListHandle->end() )
            {

                if ( iter->receiver == this )
                {
                    iter = senderListHandle->erase( iter );
                }
                else
                {
                    ++iter;
                }
            }
        }

    }
    catch ( ... )
    {
        // least of the worst options
        std::terminate();
    }
}

LsCsSignal::SignalBase *&LsCsSignal::SlotBase::get_threadLocal_currentSender()
{
#ifdef __APPLE__
    static __thread LsCsSignal::SignalBase *threadLocal_currentSender = nullptr;
#else
    static thread_local LsCsSignal::SignalBase *threadLocal_currentSender = nullptr;
#endif

    return threadLocal_currentSender;
}

bool LsCsSignal::SlotBase::compareThreads() const
{
    return true;
}

void LsCsSignal::SlotBase::queueSlot( PendingSlot data, ConnectionKind )
{
    // calls the slot immediately
    data();
}

LsCsSignal::SignalBase *LsCsSignal::SlotBase::sender() const
{
    return get_threadLocal_currentSender();
}

std::set<LsCsSignal::SignalBase *> LsCsSignal::SlotBase::internal_senderList() const
{
    std::set<SignalBase *> retval;

    auto receiverListHandle = m_possibleSenders.lock_read();

    for ( auto &sender : *receiverListHandle )
    {
        retval.insert( const_cast<SignalBase *>( sender ) );
    }

    return retval;
}

LsCsSignal::PendingSlot::PendingSlot( SignalBase *sender, std::unique_ptr<Internal::BentoAbstract> signal_Bento,
                                      SlotBase *receiver, std::unique_ptr<Internal::BentoAbstract> slot_Bento,
                                      std::unique_ptr<Internal::TeaCupAbstract> teaCup_Data )
    : m_sender( sender ), m_signal_Bento( std::move( signal_Bento ) ), m_receiver( receiver ),
      m_slot_Bento( std::move( slot_Bento ) ), m_teaCup_Data( std::move( teaCup_Data ) )
{
}

void LsCsSignal::PendingSlot::operator()() const
{
    // invoke the slot
    m_slot_Bento->invoke( m_receiver, m_teaCup_Data.get() );
}

