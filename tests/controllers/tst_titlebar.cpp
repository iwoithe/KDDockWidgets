/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#include "../main.h"
#include "controllers/TitleBar.h"
#include "controllers/Frame.h"

#include "qtquick/Platform_qtquick.h"

#include <QQmlContext>
#include <QQmlEngine>

TEST_CASE("TitleBar Ctor")
{
    auto frame = new Controllers::Frame(nullptr, {});
    auto tb = new Controllers::TitleBar(frame);
    delete tb;
    delete frame;
}