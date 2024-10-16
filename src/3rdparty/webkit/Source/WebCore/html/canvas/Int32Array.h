/*
 * Copyright (C) 2009 Apple Inc. All rights reserved.
 * Copyright (C) 2009 Google Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef Int32Array_h
#define Int32Array_h

#include "IntegralTypedArrayBase.h"

namespace WebCore
{

class Int32Array : public IntegralTypedArrayBase<int>
{
public:
    static PassRefPtr<Int32Array> create( unsigned length );
    static PassRefPtr<Int32Array> create( int *array, unsigned length );
    static PassRefPtr<Int32Array> create( PassRefPtr<ArrayBuffer> buffer, unsigned byteOffset, unsigned length );

    // Can’t use "using" here due to a bug in the RVCT compiler.
    void set( TypedArrayBase<int> *array, unsigned offset, ExceptionCode &ec )
    {
        TypedArrayBase<int>::set( array, offset, ec );
    }
    void set( unsigned index, double value )
    {
        IntegralTypedArrayBase<int>::set( index, value );
    }

    PassRefPtr<Int32Array> subarray( int start ) const;
    PassRefPtr<Int32Array> subarray( int start, int end ) const;

private:
    Int32Array( PassRefPtr<ArrayBuffer> buffer,
                unsigned byteOffset,
                unsigned length );
    // Make constructor visible to superclass.
    friend class TypedArrayBase<int>;

    // Overridden from ArrayBufferView.
    virtual bool isIntArray() const
    {
        return true;
    }
};

} // namespace WebCore

#endif // Int32Array_h
