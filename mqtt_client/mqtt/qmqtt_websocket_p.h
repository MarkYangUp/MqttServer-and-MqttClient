/*
 * qmqtt_websocket_p.h - qmqtt socket private header
 *
 * Copyright (c) 2013  Ery Lee <ery.lee at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of mqttc nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef QMQTT_WEBSOCKET_H
#define QMQTT_WEBSOCKET_H

#ifdef QT_WEBSOCKETS_LIB

#include "qmqtt_socketinterface.h"
#include "qmqtt_websocketiodevice_p.h"
#include <QWebSocket>

namespace QMQTT
{

class WebSocket : public SocketInterface
{
public:
    WebSocket(const QString& origin, QWebSocketProtocol::Version version, bool ignoreSelfSigned,
              QObject* parent = NULL);
    virtual ~WebSocket();

    QIODevice *ioDevice()
    {
        return _ioDevice;
    }

    void connectToHost(const QHostAddress& address, quint16 port);
    void connectToHost(const QString& hostName, quint16 port);
    void disconnectFromHost();
    QAbstractSocket::SocketState state() const;
    QAbstractSocket::SocketError error() const;

    // using SocketInterface::error;

private slots:
    void sslErrors(const QList<QSslError> &errors);

private:
    QWebSocket *_socket;
    WebSocketIODevice *_ioDevice;
    bool _ignoreSelfSigned;
};

}

#endif // QT_WEBSOCKETS_LIB

#endif // QMQTT_WEBSOCKET_H
