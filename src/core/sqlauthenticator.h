/***************************************************************************
 *   Copyright (C) 2005-2022 by the Quassel Project                        *
 *   devel@quassel-irc.org                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) version 3.                                           *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#pragma once

#include "authenticator.h"

class SqlAuthenticator : public Authenticator
{
    Q_OBJECT

public:
    SqlAuthenticator(QObject* parent = nullptr);

public slots:
    /* General */
    bool isAvailable() const override;
    QString backendId() const override;
    QString displayName() const override;
    QString description() const override;
    inline QVariantList setupData() const override { return {}; }

    inline bool canChangePassword() const override { return true; }

    bool setup(const QVariantMap& settings, const QProcessEnvironment& environment, bool loadFromEnvironment) override;
    State init(const QVariantMap& settings, const QProcessEnvironment& environment, bool loadFromEnvironment) override;
    UserId validateUser(const QString& user, const QString& password) override;

    /* User handling */
    // virtual UserId getUserId(const QString &username);
};
