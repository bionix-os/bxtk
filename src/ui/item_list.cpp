#include "item_list.h"

namespace sunaba::ui {
    void ItemListProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void ItemListProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void ItemListProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void ItemListProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void ItemListProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void ItemListProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void ItemListProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void ItemListProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void ItemListProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }
    
    void ItemListProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool ItemListProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void ItemListProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant ItemListProxy::_get_drag_data(const Vector2 &at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 ItemListProxy::_get_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->getMinimumSize();
        }
        return Vector2();
    }

    String ItemListProxy::_get_tooltip(const Vector2 &at_position) const {
        if (this->element != nullptr) {
            return this->element->getTooltip(at_position);
        }
        return String();
    }

    void ItemListProxy::_gui_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool ItemListProxy::_has_point(const Vector2 &point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> ItemListProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void bindItemList(sol::state& lua) {
        lua.new_usertype<ItemList>("ItemList",
            sol::constructors<ItemList()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control>(),
            "allowReselect", sol::property(&ItemList::getAllowReselect, &ItemList::setAllowReselect),
            "allowRmbSelect", sol::property(&ItemList::getAllowRmbSelect, &ItemList::setAllowRmbSelect),
            "allowSearch", sol::property(&ItemList::getAllowSearch, &ItemList::setAllowSearch),
            "autoHeight", sol::property(&ItemList::getAutoHeight, &ItemList::setAutoHeight),
            "autoWidth", sol::property(&ItemList::getAutoWidth, &ItemList::setAutoWidth),
            "clipContents", sol::property(&ItemList::getClipContents, &ItemList::setClipContents),
            "fixedColumnWidth", sol::property(&ItemList::getFixedColumnWidth, &ItemList::setFixedColumnWidth),
            "fixedIconSize", sol::property(&ItemList::getFixedIconSize, &ItemList::setFixedIconSize),
            "focusMode", sol::property(&ItemList::getFocusMode, &ItemList::setFocusMode),
            "iconMode", sol::property(&ItemList::getIconMode, &ItemList::setIconMode),
            "iconScale", sol::property(&ItemList::getIconScale, &ItemList::setIconScale),
            "itemCount", &ItemList::getItemCount,
            "maxColumns", sol::property(&ItemList::getMaxColumns, &ItemList::setMaxColumns),
            "maxTextLines", sol::property(&ItemList::getMaxTextLines, &ItemList::setMaxTextLines),
            "sameColumnWidth", sol::property(&ItemList::getSameColumnWidth, &ItemList::setSameColumnWidth),
            "selectMode", sol::property(&ItemList::getSelectMode, &ItemList::setSelectMode),
            "textOverrunBehavior", sol::property(&ItemList::getTextOverrunBehavior, &ItemList::setTextOverrunBehavior),
            "wraparoundItems", sol::property(&ItemList::getWraparoundItems, &ItemList::setWraparoundItems),
            "addIconItem", &ItemList::addIconItem,
            "addItem", &ItemList::addItem,
            "clear", &ItemList::clear,
            "deselect", &ItemList::deselect,
            "deselectAll", &ItemList::deselectAll,
            "ensureCurrentIsVisible", &ItemList::ensureCurrentIsVisible,
            "forceUpdateListSize", &ItemList::forceUpdateListSize,
            // "getHScrollBar", &ItemList::getHScrollBar,
            "getItemAtPosition", &ItemList::getItemAtPosition,
            "getItemAutoTranslateMode", &ItemList::getItemAutoTranslateMode,
            "getItemCustomBgColor", &ItemList::getItemCustomBgColor,
            "getItemCustomFgColor", &ItemList::getItemCustomFgColor,
            "getItemIcon", &ItemList::getItemIcon,
            "getItemIconModulate", &ItemList::getItemIconModulate,
            "getItemIconRegion", &ItemList::getItemIconRegion,
            "getItemLanguage", &ItemList::getItemLanguage,
            "getItemMetadata", &ItemList::getItemMetadata,
            "getItemRect", &ItemList::getItemRect,
            "getItemText", &ItemList::getItemText,
            "getItemTextDirection", &ItemList::getItemTextDirection,
            "getItemTooltip", &ItemList::getItemTooltip,
            "getSelectedItems", &ItemList::getSelectedItems,
            // "getVScrollBar", &ItemList::getVScrollBar,
            "isAnythingSelected", &ItemList::isAnythingSelected,
            "isItemDisabled", &ItemList::isItemDisabled,
            "isItemIconTransposed", &ItemList::isItemIconTransposed,
            "isItemSelectable", &ItemList::isItemSelectable,
            "isItemTooltipEnabled", &ItemList::isItemTooltipEnabled,
            "isSelected", &ItemList::isSelected,
            "moveItem", &ItemList::moveItem,
            "removeItem", &ItemList::removeItem,
            "select", &ItemList::select,
            "setItemAutoTranslateMode", &ItemList::setItemAutoTranslateMode,
            "setItemCustomBgColor", &ItemList::setItemCustomBgColor,
            "setItemCustomFgColor", &ItemList::setItemCustomFgColor,
            "setItemDisabled", &ItemList::setItemDisabled,
            "setItemIcon", &ItemList::setItemIcon,
            "setItemIconModulate", &ItemList::setItemIconModulate,
            "setItemIconRegion", &ItemList::setItemIconRegion,
            "setItemIconTransposed", &ItemList::setItemIconTransposed,
            "setItemLanguage", &ItemList::setItemLanguage,
            "setItemMetadata", &ItemList::setItemMetadata,
            "setItemSelectable", &ItemList::setItemSelectable,
            "setItemText", &ItemList::setItemText,
            "setItemTextDirection", &ItemList::setItemTextDirection,
            "setItemTooltip", &ItemList::setItemTooltip,
            "setItemTooltipEnabled", &ItemList::setItemTooltipEnabled,
            "sortItemsByText", &ItemList::sortItemsByText,
            "cast", [](Element* element) {
                ItemListNode* node = Object::cast_to<ItemListNode>(element->getNode());
                if (node != nullptr) {
                    return new ItemList(node);
                }
                return static_cast<ItemList*>(nullptr);
            }
        );
    }
}