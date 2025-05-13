#include "h_separator.h"

namespace sunaba::ui {
    void HSeparatorProxy::_enter_tree() {
        if (element != nullptr) {
            element->enterTree();
        }
    }
    
    void HSeparatorProxy::_exit_tree() {
        if (element != nullptr) {
            element->exitTree();
        }
    }
    
    void HSeparatorProxy::_ready() {
        if (element != nullptr) {
            element->ready();
        }
    }

    void HSeparatorProxy::_process(double delta) {
        if (element != nullptr) {
            element->process(delta);
        }
    }

    void HSeparatorProxy::_physics_process(double delta) {
        if (element != nullptr) {
            element->physicsProcess(delta);
        }
    }

    void HSeparatorProxy::_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->input(event);
        }
    }

    void HSeparatorProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledInput(event);
        }
    }

    void HSeparatorProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->unhandledKeyInput(event);
        }
    }

    void HSeparatorProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (element != nullptr) {
            element->shortcutInput(event);
        }
    }

    void HSeparatorProxy::_draw() {
        if (element != nullptr) {
            element->_draw();
        }
    }

    bool HSeparatorProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (element != nullptr) {
            return element->canDropData(at_position, data);
        }
        return false;
    }

    void HSeparatorProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (element != nullptr) {
            element->dropData(at_position, data);
        }
    }

    Variant HSeparatorProxy::_get_drag_data(const Vector2 &at_position) {
        if (element != nullptr) {
            return element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 HSeparatorProxy::_get_minimum_size() const {
        if (element != nullptr) {
            return element->getMinimumSize();
        }
        return Vector2();
    }

    String HSeparatorProxy::_get_tooltip(const Vector2 &at_position) const {
        if (element != nullptr) {
            return element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void HSeparatorProxy::_gui_input(const Ref<InputEvent> &event) {
        if (element != nullptr) {
            element->guiInput(event);
        }
    }
}