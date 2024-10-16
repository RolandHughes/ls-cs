/*
 * Copyright (C) 2008 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"

#include "ExecutableAllocator.h"

#if ENABLE(ASSEMBLER)

namespace JSC
{

size_t ExecutableAllocator::pageSize = 0;

#if ENABLE(ASSEMBLER_WX_EXCLUSIVE)
void ExecutableAllocator::reprotectRegion( void *start, size_t size, ProtectionSeting setting )
{
    if ( !pageSize )
    {
        intializePageSize();
    }

    // Calculate the start of the page containing this region,
    // and account for this extra memory within size.
    intptr_t startPtr = reinterpret_cast<intptr_t>( start );
    intptr_t pageStartPtr = startPtr & ~( pageSize - 1 );
    void *pageStart = reinterpret_cast<void *>( pageStartPtr );
    size += ( startPtr - pageStartPtr );

    // Round size up
    size += ( pageSize - 1 );
    size &= ~( pageSize - 1 );

    mprotect( pageStart, size, ( setting == Writable ) ? PROTECTION_FLAGS_RW : PROTECTION_FLAGS_RX );
}
#endif

}

#endif // HAVE(ASSEMBLER)
