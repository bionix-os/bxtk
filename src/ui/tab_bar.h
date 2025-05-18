#ifndef TAB_BAR_H
#define TAB_BAR_H

#include <godot_cpp/classes/tab_bar.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define TabBarNode godot::TabBar

#include "control.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"
#include "../core/texture2d.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindTabBar(sol::state &lua);

    class TabBar;

    class TabBarProxy : public TabBarNode {
        public:
            sunaba::ui::TabBar* element = nullptr;

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

            bool _can_drop_data(const Vector2& at_position, const Variant &data) const override;

            void _drop_data(const Vector2 &at_position, const Variant &data) override;

            Variant _get_drag_data(const Vector2 &at_position) override;

            Vector2 _get_minimum_size() const override;

            String _get_tooltip(const Vector2 &at_position) const override;

            void _gui_input(const Ref<InputEvent> &event) override;

            bool _has_point(const Vector2 &point) const override;

            //Object* _make_custom_tooltip(const String &for_text) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;
    };

    class TabBar : public Control {
        private:
            TabBarNode* container = nullptr; // Pointer to the TabBar instance
            void connectContainerSignals() {
                // Connect signals specific to TabBar
                SignalFunc activeTabRearrangedFunc = 
                [this] (std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); i++)
                    {
                        args.append(av[i]);
                    }
                    if (activeTabRearrangedEvent != nullptr) {
                        activeTabRearrangedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable activeTabRearrangedCallable = StlFunctionWrapper::create_callable_from_cpp_function(activeTabRearrangedFunc);
                container->connect("active_tab_rearranged", activeTabRearrangedCallable);
                SignalFunc tabButtonPressedFunc =
                [this] (std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); i++)
                    {
                        args.append(av[i]);
                    }
                    if (tabButtonPressedEvent != nullptr) {
                        tabButtonPressedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable tabButtonPressedCallable = StlFunctionWrapper::create_callable_from_cpp_function(tabButtonPressedFunc);
                container->connect("tab_button_pressed", tabButtonPressedCallable);
                SignalFunc tabChangedFunc =
                [this] (std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); i++)
                    {
                        args.append(av[i]);
                    }
                    if (tabChangedEvent != nullptr) {
                        tabChangedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable tabChangedCallable = StlFunctionWrapper::create_callable_from_cpp_function(tabChangedFunc);
                container->connect("tab_changed", tabChangedCallable);
                SignalFunc tabClickedFunc =
                [this] (std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); i++)
                    {
                        args.append(av[i]);
                    }
                    if (tabClickedEvent != nullptr) {
                        tabClickedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable tabClickedCallable = StlFunctionWrapper::create_callable_from_cpp_function(tabClickedFunc);
                container->connect("tab_clicked", tabClickedCallable);
                SignalFunc tabClosePressedFunc =
                [this] (std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); i++)
                    {
                        args.append(av[i]);
                    }
                    if (tabClosePressedEvent != nullptr) {
                        tabClosePressedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable tabClosePressedCallable = StlFunctionWrapper::create_callable_from_cpp_function(tabClosePressedFunc);
                container->connect("tab_close_pressed", tabClosePressedCallable);
                SignalFunc tabHoveredFunc =
                [this] (std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); i++)
                    {
                        args.append(av[i]);
                    }
                    if (tabHoveredEvent != nullptr) {
                        tabHoveredEvent->emit(args);
                    }
                    return Variant();
                };
                Callable tabHoveredCallable = StlFunctionWrapper::create_callable_from_cpp_function(tabHoveredFunc);
                container->connect("tab_hovered", tabHoveredCallable);
                SignalFunc tabRmbClickedFunc =
                [this] (std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); i++)
                    {
                        args.append(av[i]);
                    }
                    if (tabRmbClickedEvent != nullptr) {
                        tabRmbClickedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable tabRmbClickedCallable = StlFunctionWrapper::create_callable_from_cpp_function(tabRmbClickedFunc);
                container->connect("tab_rmb_clicked", tabRmbClickedCallable);
                SignalFunc tabSelectedFunc =
                [this] (std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); i++)
                    {
                        args.append(av[i]);
                    }
                    if (tabSelectedEvent != nullptr) {
                        tabSelectedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable tabSelectedCallable = StlFunctionWrapper::create_callable_from_cpp_function(tabSelectedFunc);
                container->connect("tab_selected", tabSelectedCallable);
            }

        public:
            TabBar() {
                setContainer(memnew(TabBarProxy));
                onInit();
            }

            TabBar(TabBarNode* container) {
                setContainer(container);
            }

            TabBarNode* getContainer() {
                return container;
            }

            void setContainer(TabBarNode* container) {
                this->container = container;
                connectContainerSignals();
                setControl(container);
            }

            void setContainer(TabBarProxy* container) {
                this->container = container;
                container->element = this;
                connectContainerSignals();
                setControl(container);
            }

            bool getClipTabs() {
                return container->get_clip_tabs();
            }

            void setClipTabs(bool clip) {
                container->set_clip_tabs(clip);
            }

            int getCurrentTab() {
                return container->get_current_tab();
            }

            void setCurrentTab(int tab) {
                container->set_current_tab(tab);
            }

            bool getDeselectEnabled() {
                return container->get_deselect_enabled();
            }

            void setDeselectEnabled(bool enabled) {
                container->set_deselect_enabled(enabled);
            }

            bool getDragToRearrangeEnabled() {
                return container->get_drag_to_rearrange_enabled();
            }

            void setDragToRearrangeEnabled(bool enabled) {
                container->set_drag_to_rearrange_enabled(enabled);
            }

            int getFocusMode() {
                return container->get_focus_mode();
            }

            void setFocusMode(int mode) {
                container->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            int getMaxTabWidth() {
                return container->get_max_tab_width();
            }

            void setMaxTabWidth(int width) {
                container->set_max_tab_width(width);
            }

            bool getScrollToSelected() {
                return container->get_scroll_to_selected();
            }

            void setScrollToSelected(bool enabled) {
                container->set_scroll_to_selected(enabled);
            }

            bool getScrollingEnabled() {
                return container->get_scrolling_enabled();
            }

            void setScrollingEnabled(bool enabled) {
                container->set_scrolling_enabled(enabled);
            }

            bool getSelectWithRmb() {
                return container->get_select_with_rmb();
            }

            void setSelectWithRmb(bool enabled) {
                container->set_select_with_rmb(enabled);
            }

            int getTabAlignment() {
                return container->get_tab_alignment();
            }

            void setTabAlignment(int alignment) {
                container->set_tab_alignment(static_cast<godot::TabBar::AlignmentMode>(alignment));
            }

            int getTabCloseDisplayPolicy() {
                return container->get_tab_close_display_policy();
            }

            void setTabCloseDisplayPolicy(int policy) {
                container->set_tab_close_display_policy(static_cast<godot::TabBar::CloseButtonDisplayPolicy>(policy));
            }

            int getTabCount() {
                return container->get_tab_count();
            }

            void setTabCount(int count) {
                container->set_tab_count(count);
            }

            int getTabsRearrangeGroup() {
                return container->get_tabs_rearrange_group();
            }

            void setTabsRearrangeGroup(int group) {
                container->set_tabs_rearrange_group(group);
            }

            Event* activeTabRearrangedEvent;
            Event* getActiveTabRearrangedEvent() {
                return activeTabRearrangedEvent;
            }
            void setActiveTabRearrangedEvent(Event* event) {
                activeTabRearrangedEvent = event;
            }
            Event* tabButtonPressedEvent;
            Event* getTabButtonPressedEvent() {
                return tabButtonPressedEvent;
            }
            void setTabButtonPressedEvent(Event* event) {
                tabButtonPressedEvent = event;
            }
            Event* tabChangedEvent;
            Event* getTabChangedEvent() {
                return tabChangedEvent;
            }
            void setTabChangedEvent(Event* event) {
                tabChangedEvent = event;
            }
            Event* tabClickedEvent;
            Event* getTabClickedEvent() {
                return tabClickedEvent;
            }
            void setTabClickedEvent(Event* event) {
                tabClickedEvent = event;
            }
            Event* tabClosePressedEvent;
            Event* getTabClosePressedEvent() {
                return tabClosePressedEvent;
            }
            void setTabClosePressedEvent(Event* event) {
                tabClosePressedEvent = event;
            }
            Event* tabHoveredEvent;
            Event* getTabHoveredEvent() {
                return tabHoveredEvent;
            }
            void setTabHoveredEvent(Event* event) {
                tabHoveredEvent = event;
            }
            Event* tabRmbClickedEvent;
            Event* getTabRmbClickedEvent() {
                return tabRmbClickedEvent;
            }
            void setTabRmbClickedEvent(Event* event) {
                tabRmbClickedEvent = event;
            }
            Event* tabSelectedEvent;
            Event* getTabSelectedEvent() {
                return tabSelectedEvent;
            }
            void setTabSelectedEvent(Event* event) {
                tabSelectedEvent = event;
            }

            void addTab(const std::string& name, sunaba::core::Texture2D* icon = nullptr) {
                godot::Texture2D* iconTexture = 
                    icon != nullptr 
                        ? icon->getTexture2D() 
                        : nullptr;
                Ref<godot::Texture2D> iconRef = 
                    iconTexture != nullptr 
                        ? Ref<godot::Texture2D>(iconTexture) 
                        : Ref<godot::Texture2D>();
                container->add_tab(name.c_str(), iconRef);
            }

            void clearTabs() {
                container->clear_tabs();
            }

            void ensureTabVisible(int tab) {
                container->ensure_tab_visible(tab);
            }

            bool getOffsetButtonsVisible() {
                return container->get_offset_buttons_visible();
            }

            int getPreviousTab() {
                return container->get_previous_tab();
            }

            sunaba::core::Texture2D* getTabButtonIcon(int tab) {
                return new sunaba::core::Texture2D(container->get_tab_button_icon(tab).ptr());
            }

            sunaba::core::Texture2D* getTabIcon(int tab) {
                return new sunaba::core::Texture2D(container->get_tab_icon(tab).ptr());
            }

            int getTabIconMaxWidth(int tab) {
                return container->get_tab_icon_max_width(tab);
            }

            int getTabIdxAtPoint(const Vector2& point) {
                return container->get_tab_idx_at_point(point);
            }

            std::string getTabLanguage(int tab) {
                return String(container->get_tab_language(tab)).utf8().get_data();
            }

            Variant getTabMetadata(int tab) {
                return container->get_tab_metadata(tab);
            }

            int getTabOffset() {
                return container->get_tab_offset();
            }

            Rect2 getTabRect(int tab) {
                return container->get_tab_rect(tab);
            }

            int getTabTextDirection(int tab) {
                return container->get_tab_text_direction(tab);
            }

            std::string getTabTitle(int tab) {
                return String(container->get_tab_title(tab)).utf8().get_data();
            }

            std::string getTabTooltip(int tab) {
                return String(container->get_tab_tooltip(tab)).utf8().get_data();
            }

            bool isTabDisabled(int tab) {
                return container->is_tab_disabled(tab);
            }

            bool isTabHidden(int tab) {
                return container->is_tab_hidden(tab);
            }

            void moveTab(int from, int to) {
                container->move_tab(from, to);
            }

            void removeTab(int tab) {
                container->remove_tab(tab);
            }

            bool selectNextAvailable() {
                return container->select_next_available();
            }

            bool selectPreviousAvailable() {
                return container->select_previous_available();
            }

            void setTabButtonIcon(int tab, sunaba::core::Texture2D* icon) {
                godot::Texture2D* iconTexture = 
                    icon != nullptr 
                        ? icon->getTexture2D() 
                        : nullptr;
                Ref<godot::Texture2D> iconRef = 
                    iconTexture != nullptr 
                        ? Ref<godot::Texture2D>(iconTexture) 
                        : Ref<godot::Texture2D>();
                container->set_tab_button_icon(tab, iconRef);
            }

            void setTabDisabled(int tab, bool disabled) {
                container->set_tab_disabled(tab, disabled);
            }

            void setTabHidden(int tab, bool hidden) {
                container->set_tab_hidden(tab, hidden);
            }

            void setTabIcon(int tab, sunaba::core::Texture2D* icon) {
                godot::Texture2D* iconTexture = 
                    icon != nullptr 
                        ? icon->getTexture2D() 
                        : nullptr;
                Ref<godot::Texture2D> iconRef = 
                    iconTexture != nullptr 
                        ? Ref<godot::Texture2D>(iconTexture) 
                        : Ref<godot::Texture2D>();
                container->set_tab_icon(tab, iconRef);
            }

            void setTabIconMaxWidth(int tab, int width) {
                container->set_tab_icon_max_width(tab, width);
            }

            void setTabLanguage(int tab, const std::string& language) {
                container->set_tab_language(tab, language.c_str());
            }

            void setTabMetadata(int tab, const Variant& metadata) {
                container->set_tab_metadata(tab, metadata);
            }
    };
}

#endif // TAB_BAR_H