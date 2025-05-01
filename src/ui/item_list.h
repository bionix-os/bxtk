#ifndef ITEM_LIST_H
#define ITEM_LIST_H

#include <godot_cpp/classes/item_list.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define ItemListNode godot::ItemList

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindItemList(sol::state &lua);

    class ItemList;

    class ItemListProxy : public ItemListNode {
        public:
            sunaba::ui::ItemList* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override ;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;

            void _draw() override;
            
            void _gui_input(const Ref<InputEvent>& event) override;
            bool _has_point(const Vector2 &point) const override;
            String _get_tooltip(const Vector2 &at_position) const override;
            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
        };

        class ItemList : public Control {
        private:
            ItemListNode* item_list = nullptr; // Pointer to the ItemList instance

            void connectItemListSignals() {
                // Connect signals from the item list to the element
                // Example: item_list->connect("signal_name", this, "method_name");
            }

        public:
            ItemList() {
                setItemList(memnew(ItemListProxy));
                onInit();
            }

            ItemListNode* getItemList() {
                return item_list;
            }

            void setItemList(ItemListNode* node) {
                item_list = node;
                connectItemListSignals();
                setControl(item_list);
            }

            void setItemListProxy(ItemListProxy* node) {
                item_list = node;
                node->element = this;
                connectItemListSignals();
                setControl(item_list);
            }

            bool getAllowReselect() {
                return item_list->get_allow_reselect();
            }

            void setAllowReselect(bool allow) {
                item_list->set_allow_reselect(allow);
            }

            bool getAllowRmbSelect() {
                return item_list->get_allow_rmb_select();
            }

            void setAllowRmbSelect(bool allow) {
                item_list->set_allow_rmb_select(allow);
            }

            bool getAllowSearch() {
                return item_list->get_allow_search();
            }

            void setAllowSearch(bool allow) {
                item_list->set_allow_search(allow);
            }

            bool getAutoHeight() {
                return item_list->has_auto_height();
            }

            void setAutoHeight(bool enable) {
                item_list->set_auto_height(enable);
            }

            bool getAutoWidth() {
                return item_list->has_auto_width();
            }

            void setAutoWidth(bool enable) {
                item_list->set_auto_width(enable);
            }

            bool getClipContents() {
                return item_list->is_clipping_contents();
            }

            void setClipContents(bool enable) {
                item_list->set_clip_contents(enable);
            }

            int getFixedColumnWidth() {
                return item_list->get_fixed_column_width();
            }

            void setFixedColumnWidth(int width) {
                item_list->set_fixed_column_width(width);
            }

            Vector2i getFixedIconSize() {
                return item_list->get_fixed_icon_size();
            }

            void setFixedIconSize(Vector2i size) {
                item_list->set_fixed_icon_size(size);
            }

            int getFocusMode() {
                return item_list->get_focus_mode();
            }

            void setFocusMode(int mode) {
                item_list->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            int getIconMode() {
                return item_list->get_icon_mode();
            }

            void setIconMode(int mode) {
                item_list->set_icon_mode(static_cast<godot::ItemList::IconMode>(mode));
            }

            float getIconScale() {
                return item_list->get_icon_scale();
            }

            void setIconScale(float scale) {
                item_list->set_icon_scale(scale);
            }

            int getItemCount() {
                return item_list->get_item_count();
            }

            void setItemCount(int count) {
                item_list->set_item_count(count);
            }

            int getMaxColumns() {
                return item_list->get_max_columns();
            }

            void setMaxColumns(int columns) {
                item_list->set_max_columns(columns);
            }

            int getMaxTextLines() {
                return item_list->get_max_text_lines();
            }

            void setMaxTextLines(int lines) {
                item_list->set_max_text_lines(lines);
            }

            bool getSameColumnWidth() {
                return item_list->is_same_column_width();
            }

            void setSameColumnWidth(bool enable) {
                item_list->set_same_column_width(enable);
            }

            int getSelectMode() {
                return item_list->get_select_mode();
            }

            void setSelectMode(int mode) {
                item_list->set_select_mode(static_cast<godot::ItemList::SelectMode>(mode));
            }

            int getTextOverrunBehavior() {
                return item_list->get_text_overrun_behavior();
            }

            void setTextOverrunBehavior(int behavior) {
                item_list->set_text_overrun_behavior(static_cast<godot::TextServer::OverrunBehavior>(behavior));
            }

            bool getWraparoundItems() {
                return item_list->has_wraparound_items();
            }

            void setWraparoundItems(bool enable) {
                item_list->set_wraparound_items(enable);
            }

            Event* emptyClickedEvent;
            Event* getEmptyClickedEvent() {
                return emptyClickedEvent;
            }
            void setEmptyClickedEvent(Event* event) {
                emptyClickedEvent = event;
            }
            Event* itemActivatedEvent;
            Event* getItemActivatedEvent() {
                return itemActivatedEvent;
            }
            void setItemActivatedEvent(Event* event) {
                itemActivatedEvent = event;
            }
            Event* itemClickedEvent;
            Event* getItemClickedEvent() {
                return itemClickedEvent;
            }
            void setItemClickedEvent(Event* event) {
                itemClickedEvent = event;
            }
            Event* itemSelectedEvent;
            Event* getItemSelectedEvent() {
                return itemSelectedEvent;
            }
            void setItemSelectedEvent(Event* event) {
                itemSelectedEvent = event;
            }
            Event* multiSelectedEvent;
            Event* getMultiSelectedEvent() {
                return multiSelectedEvent;
            }
            void setMultiSelectedEvent(Event* event) {
                multiSelectedEvent = event;
            }

            int addIconItem(sunaba::core::Texture2D* texture, bool selectable = true) {
                Ref<godot::Texture2D> textureRef = Ref<godot::Texture2D>(texture->getTexture());
                return item_list->add_icon_item(textureRef, selectable);
            }

            int addItem(std::string text, sunaba::core::Texture2D* icon = nullptr, bool selectable = true) {
                Ref<godot::Texture2D> textureRef;
                if (icon != nullptr) {
                    textureRef = Ref<godot::Texture2D>(icon->getTexture());
                }
                return item_list->add_item(text.c_str(), textureRef, selectable);
            }

            void clear() {
                item_list->clear();
            }

            void deselect(int index) {
                item_list->deselect(index);
            }

            void deselectAll() {
                item_list->deselect_all();
            }

            void ensureCurrentIsVisible() {
                item_list->ensure_current_is_visible();
            }

            void forceUpdateListSize() {
                item_list->force_update_list_size();
            }

            //HScrollBar* getHScrollBar() {
            //    return new HScrollBar(item_list->get_h_scroll_bar());
            //}

            int getItemAtPosition(Vector2 position, bool exact = false) {
                return item_list->get_item_at_position(position, exact);
            }

            int getItemAutoTranslateMode(int index) {
                return item_list->get_item_auto_translate_mode(index);
            }

            Color getItemCustomBgColor(int index) {
                return item_list->get_item_custom_bg_color(index);
            }

            Color getItemCustomFgColor(int index) {
                return item_list->get_item_custom_fg_color(index);
            }

            sunaba::core::Texture2D* getItemIcon(int index) {
                Ref<godot::Texture2D> textureRef = item_list->get_item_icon(index);
                return new sunaba::core::Texture2D(textureRef.ptr());
            }

            Color getItemIconModulate(int index) {
                return item_list->get_item_icon_modulate(index);
            }

            Rect2 getItemIconRegion(int index) {
                return item_list->get_item_icon_region(index);
            }

            std::string getItemLanguage(int index) {
                return item_list->get_item_language(index).utf8().get_data();
            }

            Variant getItemMetadata(int index) {
                return item_list->get_item_metadata(index);
            }

            std::string getItemText(int index) {
                return item_list->get_item_text(index).utf8().get_data();
            }

            int getItemTextDirection(int index) {
                return item_list->get_item_text_direction(index);
            }

            std::string getItemTooltip(int index) {
                return item_list->get_item_tooltip(index).utf8().get_data();
            }

            std::vector<int> getSelectedItems() {
                PackedInt32Array selectedItems = item_list->get_selected_items();
                std::vector<int> result;
                for (int i = 0; i < selectedItems.size(); i++) {
                    result.push_back(selectedItems[i]);
                }
                return result;
            }

            //VScrollBar* getVScrollBar() {
            //    return new VScrollBar(item_list->get_v_scroll_bar());
            //}
    };
}

#endif // ITEM_LIST_H