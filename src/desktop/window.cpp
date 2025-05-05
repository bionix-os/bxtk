#include "window.h"

namespace sunaba::desktop {
    void WindowProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void WindowProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void WindowProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void WindowProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void WindowProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void WindowProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void WindowProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void WindowProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void WindowProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void bindWindow(sol::state_view& lua) {
        lua.new_usertype<Window>("Window",
            sol::constructors<Window()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::Viewport>(),
            "alwaysOnTop", sol::property(
                &Window::getAlwaysOnTop,
                &Window::setAlwaysOnTop
            ),
            "autoTranslate", sol::property(
                &Window::getAutoTranslate,
                &Window::setAutoTranslate
            ),
            "borderless", sol::property(
                &Window::getBorderless,
                &Window::setBorderless
            ),
            "contentScaleAspect", sol::property(
                &Window::getContentScaleAspect,
                &Window::setContentScaleAspect
            ),
            "contentScaleFactor", sol::property(
                &Window::getContentScaleFactor,
                &Window::setContentScaleFactor
            ),
            "contentScaleMode", sol::property(
                &Window::getContentScaleMode,
                &Window::setContentScaleMode
            ),
            "contentScaleSize", sol::property(
                &Window::getContentScaleSize,
                &Window::setContentScaleSize
            ),
            "contentScaleStretch", sol::property(
                &Window::getContentScaleStretch,
                &Window::setContentScaleStretch
            ),
            "currentScreen", sol::property(
                &Window::getCurrentScreen,
                &Window::setCurrentScreen
            ),
            "excludeFromCapture", sol::property(
                &Window::getExcludeFromCapture,
                &Window::setExcludeFromCapture
            ),
            "exclusive", sol::property(
                &Window::getExclusive,
                &Window::setExclusive
            ),
            "extendToTitle", sol::property(
                &Window::getExtendToTitle,
                &Window::setExtendToTitle
            ),
            "forceNative", sol::property(
                &Window::getForceNative,
                &Window::setForceNative
            ),
            "initialPosition", sol::property(
                &Window::getInitialPosition,
                &Window::setInitialPosition
            ),
            "keepTitleVisible", sol::property(
                &Window::getKeepTitleVisible,
                &Window::setKeepTitleVisible
            ),
            "maxSize", sol::property(
                &Window::getMaxSize,
                &Window::setMaxSize
            ),
            "minSize", sol::property(
                &Window::getMinSize,
                &Window::setMinSize
            ),
            "mode", sol::property(
                &Window::getMode,
                &Window::setMode
            ),
            "mousePassthrough", sol::property(
                &Window::getMousePassthrough,
                &Window::setMousePassthrough
            ),
            "mousePassthroughPolygon", sol::property(
                &Window::getMousePassthroughPolygon,
                &Window::setMousePassthroughPolygon
            ),
            "popupWindow", sol::property(
                &Window::getPopupWindow,
                &Window::setPopupWindow
            ),
            "position", sol::property(
                &Window::getPosition,
                &Window::setPosition
            ),
            "sharpCorners", sol::property(
                &Window::getSharpCorners,
                &Window::setSharpCorners
            ),
            "size", sol::property(
                &Window::getSize,
                &Window::setSize
            ),
            "theme", sol::property(
                &Window::getTheme,
                &Window::setTheme
            ),
            "themeTypeVariation", sol::property(
                &Window::getThemeTypeVariation,
                &Window::setThemeTypeVariation
            ),
            "title", sol::property(
                &Window::getTitle,
                &Window::setTitle
            ),
            "transient", sol::property(
                &Window::getTransient,
                &Window::setTransient
            ),
            "transientToFocused", sol::property(
                &Window::getTransientToFocused,
                &Window::setTransientToFocused
            ),
            "transparent", sol::property(
                &Window::getTransparent,
                &Window::setTransparent
            ),
            "unfocusable", sol::property(
                &Window::getUnfocusable,
                &Window::setUnfocusable
            ),
            "unresizable", sol::property(
                &Window::getUnresizable,
                &Window::setUnresizable
            ),
            "visible", sol::property(
                &Window::getVisible,
                &Window::setVisible
            ),
            "wrapControls", sol::property(
                &Window::getWrapControls,
                &Window::setWrapControls
            ),
            "aboutToPopup", sol::property(
                &Window::getAboutToPopupEvent,
                &Window::setAboutToPopupEvent
            ),
            "closeRequested", sol::property(
                &Window::getCloseRequestedEvent,
                &Window::setCloseRequestedEvent
            ),
            "dpiChanged", sol::property(
                &Window::getDpiChangedEvent,
                &Window::setDpiChangedEvent
            ),
            "filesDropped", sol::property(
                &Window::getFilesDroppedEvent,
                &Window::setFilesDroppedEvent
            ),
            "focusEntered", sol::property(
                &Window::getFocusEnteredEvent,
                &Window::setFocusEnteredEvent
            ),
            "focusExited", sol::property(
                &Window::getFocusExitedEvent,
                &Window::setFocusExitedEvent
            ),
            "goBackRequested", sol::property(
                &Window::getGoBackRequestedEvent,
                &Window::setGoBackRequestedEvent
            ),
            "mouseEntered", sol::property(
                &Window::getMouseEnteredEvent,
                &Window::setMouseEnteredEvent
            ),
            "mouseExited", sol::property(
                &Window::getMouseExitedEvent,
                &Window::setMouseExitedEvent
            ),
            "themeChanged", sol::property(
                &Window::getThemeChangedEvent,
                &Window::setThemeChangedEvent
            ),
            "titleChanged", sol::property(
                &Window::getTitleChangedEvent,
                &Window::setTitleChangedEvent
            ),
            "titlebarChanged", sol::property(
                &Window::getTitlebarChangedEvent,
                &Window::setTitlebarChangedEvent
            ),
            "visibilityChanged", sol::property(
                &Window::getVisibilityChangedEvent,
                &Window::setVisibilityChangedEvent
            ),
            "windowInput", sol::property(
                &Window::getWindowInputEvent,
                &Window::setWindowInputEvent
            ),
            "getContentsMinimumSize", &Window::getContentsMinimumSize,
            "addThemeColorOverride", &Window::addThemeColorOverride,
            "addThemeConstantOverride", &Window::addThemeConstantOverride,
            "addThemeFontOverride", &Window::addThemeFontOverride,
            "addTHemeFontSizeOverride", &Window::addThemeFontSizeOverride,
            "addThemeIconOverride", &Window::addThemeIconOverride,
            "addThemeStyleBoxOverride", &Window::addThemeStyleBoxOverride,
            "beginBulkThemeOverride", &Window::beginBulkThemeOverride,
            "canDraw", &Window::canDraw,
            "childControlsChanged", &Window::childControlsChanged,
            "endBulkThemeOverride", &Window::endBulkThemeOverride,
            "getFlag", &Window::getFlag,
            "getLayoutDirection", &Window::getLayoutDirection,
            "getPositionWithDecorations", &Window::getPositionWithDecorations,
            "getSizeWithDecorations", &Window::getSizeWithDecorations,
            "getThemeColor", &Window::getThemeColor,
            "getThemeConstant", &Window::getThemeConstant,
            "getThemeDefaultBaseScale", &Window::getThemeDefaultBaseScale, 
            "getThemeDefaultFont", &Window::getThemeDefaultFont,
            "getThemeDefaultFontSize", &Window::getThemeDefaultFontSize,
            "getThemeFont", &Window::getThemeFont,
            "getThemeFontSize", &Window::getThemeFontSize,
            "getThemeIcon", &Window::getThemeIcon,
            "getThemeStyleBox", &Window::getThemeStyleBox,
            "getWindowId", &Window::getWindowId,
            "grabFocus", &Window::grabFocus,
            "hasFocus", &Window::hasFocus,
            "hasThemeColor", &Window::hasThemeColor,
            "hasThemeColorOverride", &Window::hasThemeColorOverride,
            "hasThemeConstant", &Window::hasThemeConstant,
            "hasThemeConstantOverride", &Window::hasThemeConstantOverride,
            "hasThemeFont", &Window::hasThemeFont,
            "hasThemeFontOverride", &Window::hasThemeFontOverride,
            "hasThemeFontSize", &Window::hasThemeFontSize,
            "hasThemeFontSizeOverride", &Window::hasThemeFontSizeOverride,
            "hasThemeIcon", &Window::hasThemeIcon,
            "hasThemeIconOverride", &Window::hasThemeIconOverride,
            "hasThemeStyleBox", &Window::hasThemeStyleBox,
            "hasThemeStyleBoxOverride", &Window::hasThemeStyleBoxOverride,
            "hide", &Window::hide,
            "isEmbedded", &Window::isEmbedded,
            "isLayoutRtl", &Window::isLayoutRtl,
            "isMaximizeAllowed", &Window::isMaximizeAllowed,
            "isUsingFontOversampling", &Window::isUsingFontOversampling,
            "moveToCenter", &Window::moveToCenter,
            "moveToForground", &Window::moveToForground,
            "popup", &Window::popup,
            "popupCentered", &Window::popupCentered,
        );
    }
}