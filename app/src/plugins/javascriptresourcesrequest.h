/*
 * Copyright (C) 2016 Stuart Howarth <showarth@marxoft.co.uk>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef JAVASCRIPTRESOURCESREQUEST_H
#define JAVASCRIPTRESOURCESREQUEST_H

#include "resourcesrequest.h"
#include "javascriptresourcesrequestglobalobject.h"

class QScriptEngine;

class JavaScriptResourcesRequest : public ResourcesRequest
{
    Q_OBJECT

    Q_PROPERTY(QString fileName READ fileName)
    Q_PROPERTY(QString id READ id)

public:
    explicit JavaScriptResourcesRequest(const QString &id, const QString &fileName, QObject *parent = 0);

    QString fileName() const;

    QString id() const;

    virtual QString errorString() const;

    virtual QVariant result() const;

    virtual Status status() const;

public Q_SLOTS:
    virtual bool cancel();
    virtual bool del(const QString &sourceType, const QString &sourceId, const QString &destinationType,
                     const QString &destinationId);
    virtual bool get(const QString &resourceType, const QString &resourceId);
    virtual bool insert(const QString &sourceType, const QString &sourceId, const QString &destinationType,
                        const QString &destinationId);
    virtual bool list(const QString &resourceType, const QString &resourceId);
    virtual bool search(const QString &resourceType, const QString &query, const QString &order);

private Q_SLOTS:
    void onRequestError(const QString &errorString);
    void onRequestFinished(const QVariant &result);

private:
    void setErrorString(const QString &e);
    
    void setResult(const QVariant &r);
    
    void setStatus(Status s);
    
    void initEngine();
    
    JavaScriptResourcesRequestGlobalObject *m_global;
    QScriptEngine *m_engine;
    
    QString m_fileName;
    QString m_id;

    QString m_errorString;

    QVariant m_result;

    Status m_status;
    
    bool m_evaluated;
};

#endif // JAVASCRIPTSERVICEPLUGIN_H
