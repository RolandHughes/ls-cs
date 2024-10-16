/*
 * Copyright (C) 2008 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "RegisterFile.h"

namespace JSC
{

RegisterFile::~RegisterFile()
{
#if HAVE(MMAP)
    munmap( reinterpret_cast<char *>( m_buffer ), ( ( m_max - m_start ) + m_maxGlobals ) * sizeof( Register ) );
#elif HAVE(VIRTUALALLOC)
#if OS(WINCE)
    VirtualFree( m_buffer, DWORD( m_commitEnd ) - DWORD( m_buffer ), MEM_DECOMMIT );
#endif
    VirtualFree( m_buffer, 0, MEM_RELEASE );
#elif OS(SYMBIAN)
    delete m_registerFileAllocator;
#else
    fastFree( m_buffer );
#endif
}

void RegisterFile::releaseExcessCapacity()
{
#if OS(QNX)
    size_t sizeForGlobals = roundUpAllocationSize( m_maxGlobals * sizeof( Register ), commitSize );
    Register *endOfGlobals = reinterpret_cast<Register *>( reinterpret_cast<char *>( m_buffer ) + sizeForGlobals );
    size_t decommitSize = ( m_max - endOfGlobals ) * sizeof( Register );

    if ( decommitSize > 0 )
    {
        if ( mmap( endOfGlobals, decommitSize, PROT_NONE, MAP_FIXED|MAP_LAZY|MAP_PRIVATE|MAP_ANON, -1, 0 ) == MAP_FAILED )
        {
            fprintf( stderr, "Could not decommit register file memory: %d\n", errno );
        }
    }

    m_commitEnd = endOfGlobals;

#elif HAVE(MMAP) && HAVE(MADV_FREE) && !HAVE(VIRTUALALLOC)

    while ( madvise( m_start, ( m_max - m_start ) * sizeof( Register ), MADV_FREE ) == -1 && errno == EAGAIN ) { }

#elif HAVE(VIRTUALALLOC)
    VirtualFree( m_start, ( m_max - m_start ) * sizeof( Register ), MEM_DECOMMIT );
    m_commitEnd = m_start;
#endif
    m_maxUsed = m_start;
}

} // namespace JSC
