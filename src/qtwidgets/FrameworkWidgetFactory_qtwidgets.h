/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#ifndef KDDOCKWIDGETS_FRAMEWORKWIDGETFACTORY_QTWIDGETS_H
#define KDDOCKWIDGETS_FRAMEWORKWIDGETFACTORY_QTWIDGETS_H

#include "FrameworkWidgetFactory.h"

// clazy:excludeall=ctor-missing-parent-argument

/**
 * @file
 * @brief A factory class for allowing the user to customize some internal widgets.
 *
 * @author Sérgio Martins \<sergio.martins@kdab.com\>
 */

QT_BEGIN_NAMESPACE
class QAbstractButton;
QT_END_NAMESPACE

namespace Layouting {
class Widget;
}

namespace KDDockWidgets {

class DropIndicatorOverlayInterface;
class DropArea;

namespace Controllers {
class Separator;
class TabBar;
class SideBar;
class FloatingWindow;
class MainWindow;
}

/**
 * @brief The FrameworkWidgetFactory that's used if none is specified.
 */
class DOCKS_EXPORT DefaultWidgetFactory_qtwidgets : public FrameworkWidgetFactory
{
    Q_OBJECT
public:
    DefaultWidgetFactory_qtwidgets() = default;
    ~DefaultWidgetFactory_qtwidgets() override;
    View *createMainWindow(Controllers::MainWindow *, View *, Qt::WindowFlags) const override;
    View *createDockWidget(Controllers::DockWidget *, Qt::WindowFlags) const override;
    View *createFrame(Controllers::Frame *, View *parent, FrameOptions options = FrameOption_None) const override;
    View *createTitleBar(Controllers::TitleBar *, Controllers::Frame *) const override;
    View *createTitleBar(Controllers::TitleBar *, Controllers::FloatingWindow *) const override;
    View *createTabWidget(Controllers::Stack *, Controllers::Frame *parent) const override;
    View *createTabBar(Controllers::TabBar *tabBar, View *parent) const override;
    View *createSeparator(Controllers::Separator *, View *parent = nullptr) const override;
    View *createFloatingWindow(Controllers::FloatingWindow *,
                               Controllers::MainWindow *parent = nullptr,
                               Qt::WindowFlags windowFlags = {}) const override;
    DropIndicatorOverlayInterface *createDropIndicatorOverlay(DropArea *) const override;
    QWidgetOrQuick *createRubberBand(QWidgetOrQuick *parent) const override;
    View *createSideBar(Controllers::SideBar *, Controllers::MainWindow *parent) const override;

#ifdef KDDOCKWIDGETS_QTWIDGETS
    QAbstractButton *createTitleBarButton(QWidget *parent, TitleBarButtonType) const override;
#else
    Q_INVOKABLE QUrl titleBarFilename() const override;
    QUrl dockwidgetFilename() const override;
    QUrl frameFilename() const override;
    QUrl floatingWindowFilename() const override;
#endif

    QIcon iconForButtonType(TitleBarButtonType type, qreal dpr) const override;

private:
    Q_DISABLE_COPY(DefaultWidgetFactory_qtwidgets)
};

}

#endif