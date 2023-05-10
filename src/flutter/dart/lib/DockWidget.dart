/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

import 'package:KDDockWidgets/PositionedWidget.dart';
import 'package:KDDockWidgets/View_mixin.dart';
import 'package:KDDockWidgetsBindings/Bindings.dart' as KDDockWidgetBindings;
import 'package:KDDockWidgetsBindings/Bindings_KDDWBindingsFlutter.dart'
    as KDDWBindingsFlutter;
import 'package:flutter/material.dart' hide View;

class DockWidget extends KDDWBindingsFlutter.DockWidget with View_mixin {
  DockWidget(String? uniqueName, {int options = 0, int layoutSaverOptions = 0})
      : super(uniqueName,
            options: options, layoutSaverOptions: layoutSaverOptions) {
    initMixin(this, color: Colors.pink, debugName: "DockWidget");
    m_fillsParent = true;
    // print("DockWidget CTOR");
  }

  Widget createFlutterWidget() {
    return DockWidgetWidget(kddwView, this, key: widgetKey);
  }
}

class DockWidgetWidget extends PositionedWidget {
  final DockWidget DockWidgetView;
  DockWidgetWidget(var kddwView, this.DockWidgetView, {Key? key})
      : super(kddwView, key: key);

  @override
  State<PositionedWidget> createState() {
    return DockWidgetPositionedWidgetState(kddwView, DockWidgetView);
  }
}

class DockWidgetPositionedWidgetState extends PositionedWidgetState {
  final DockWidget DockWidgetView;

  DockWidgetPositionedWidgetState(var kddwView, this.DockWidgetView)
      : super(kddwView);

  @override
  Widget buildContents() {
    return super.buildContents();
  }
}
