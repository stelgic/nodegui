#pragma once

#include <QObject>
#include <QList>
#include <QVariant>

#include "Extras/Export/export.h"

class DLL_EXPORT QWebData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QVariant> value READ value NOTIFY valueChanged)

public:
    //using QObject::QObject;
    explicit QWebData(QObject *parent = Q_NULLPTR) 
        : QObject(parent) {}

    QList<QVariant> value() const
    {
        return m_value;
    }

public slots:
    void setValue(const QList<QVariant>& value)
    {
        m_value.clear();
        for (int i = 0; i < value.size(); ++i) {
            m_value.append(value[i]);
        }
        emit valueChanged(m_value);
    }

signals:
    void valueChanged(const QList<QVariant>& value);
private:
    QList<QVariant> m_value;
};

Q_DECLARE_METATYPE(QWebData);
Q_DECLARE_METATYPE(QList<QVariant>);
