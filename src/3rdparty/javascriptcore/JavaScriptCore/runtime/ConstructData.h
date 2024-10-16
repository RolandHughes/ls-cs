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

#ifndef ConstructData_h
#define ConstructData_h

namespace JSC
{

class ArgList;
class ExecState;
class FunctionExecutable;
class JSObject;
class JSValue;
class ScopeChainNode;

enum ConstructType
{
    ConstructTypeNone,
    ConstructTypeHost,
    ConstructTypeJS
};

typedef JSObject *( *NativeConstructor )( ExecState *, JSObject *, const ArgList & );

#ifdef QT_BUILD_SCRIPT_LIB
class NativeConstrWrapper
{
    NativeConstructor ptr;
    //Hack. If this variable is true and if debugger is attached at the end of
    //operator() execution functionExit event will be created (in most cases it will be default)
    //This variable was created because of FunctionWrapper::proxyCall method that change result
    //on fly. Event shuld be created with original value so the method should call it itself.
    bool callDebuggerFunctionExit;
public:
    inline NativeConstrWrapper &operator=( NativeConstructor func )
    {
        callDebuggerFunctionExit = true;
        ptr = func;
        return *this;
    }
    inline operator NativeConstructor() const
    {
        return ptr;
    }
    inline operator bool() const
    {
        return ptr;
    }

    inline void doNotCallDebuggerFunctionExit()
    {
        callDebuggerFunctionExit = false;
    }
    JSObject *operator()( ExecState *, JSObject *, const ArgList & ) const;
};
#endif

#if defined(QT_BUILD_SCRIPT_LIB) && OS(SOLARIS)
struct
#else
union
#endif
    ConstructData
{
    struct
    {
#ifndef QT_BUILD_SCRIPT_LIB
        NativeConstructor function;
#else
        NativeConstrWrapper function;
#endif
    } native;
    struct
    {
        FunctionExecutable *functionExecutable;
        ScopeChainNode *scopeChain;
    } js;
};

JSObject *construct( ExecState *, JSValue constructor, ConstructType, const ConstructData &, const ArgList & );

} // namespace JSC

#endif // ConstructData_h
