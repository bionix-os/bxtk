package bxtk.ui;

import bxtk.desktop.PopupMenu;

@:native("MenuButton")
extern class MenuButton extends Button {
    public var itemCount: Int;
    public var switchOnHover: Bool;
    public var aboutToPopup: bxtk.core.Event;
    public function getPopup(): PopupMenu;
    public function setDisableShortcuts(disable: Bool): Void;
    public function showPopup(): Void;
    @:native("cast")
    public static function toMenuButton(obj: Dynamic): bxtk.ui.MenuButton;
}

abstract MenuButtonAbstract(MenuButton) from MenuButton to MenuButton {
    @:from
    public static function fromElement(element: bxtk.core.Element): MenuButtonAbstract {
        var menuButton = bxtk.ui.MenuButton.toMenuButton(element);
        if (menuButton.isNull()) {
            return null;
        }
        return menuButton;
    }
}