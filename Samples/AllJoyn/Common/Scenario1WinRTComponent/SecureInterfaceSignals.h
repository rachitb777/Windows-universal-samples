//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************
//-----------------------------------------------------------------------------
// <auto-generated>
//   This code was generated by a tool.
//
//   Changes to this file may cause incorrect behavior and will be lost if
//   the code is regenerated.
//
//   For more information, see: http://go.microsoft.com/fwlink/?LinkID=623246
// </auto-generated>
//-----------------------------------------------------------------------------
#pragma once

namespace com { namespace microsoft { namespace Samples { namespace SecureInterface {

ref class SecureInterfaceSignals;

public interface class ISecureInterfaceSignals
{
    event Windows::Foundation::TypedEventHandler<SecureInterfaceSignals^, SecureInterfaceTextSentReceivedEventArgs^>^ TextSentReceived;
};

public ref class SecureInterfaceSignals sealed : [Windows::Foundation::Metadata::Default] ISecureInterfaceSignals
{
public:
    // "This signal is emitted when producer sends a text message to consumer"
    // Calling this method will send the TextSent signal to every member of the session.
    void TextSent(_In_ Platform::String^ interfaceMemberMessage);

    // This event fires whenever the TextSent signal is sent by another member of the session.
    virtual event Windows::Foundation::TypedEventHandler<SecureInterfaceSignals^, SecureInterfaceTextSentReceivedEventArgs^>^ TextSentReceived 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<SecureInterfaceSignals^, SecureInterfaceTextSentReceivedEventArgs^>^ handler) 
        { 
            return _TextSentReceived += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<SecureInterfaceSignals^>(sender), safe_cast<SecureInterfaceTextSentReceivedEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _TextSentReceived -= token; 
        } 
    internal: 
        void raise(SecureInterfaceSignals^ sender, SecureInterfaceTextSentReceivedEventArgs^ args) 
        { 
            _TextSentReceived(sender, args);
        } 
    }

internal:
    void Initialize(_In_ ISignalEmitter^ emitter);
    void CallTextSentReceived(_In_ SecureInterfaceSignals^ sender, _In_ SecureInterfaceTextSentReceivedEventArgs^ args);

private:
    ISignalEmitter^ m_emitter;

    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _TextSentReceived;

    alljoyn_interfacedescription_member m_memberTextSent;
};

} } } } 
