#ifndef FLOW_CONTAINER_H
#define FLOW_CONTAINER_H

#include <godot_cpp/classes/flow_container.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define FlowContainerNode godot::FlowContainer

#include "container.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::ui {
    void bindFlowContainer(sol::state& lua);

    class FlowContainer;

    class FlowContainerProxy : public FlowContainerNode {
        public:
            sunaba::ui::FlowContainer* element = nullptr;

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

            PackedInt32Array _get_allowed_size_flags_horizontal() const override;

            PackedInt32Array _get_allowed_size_flags_vertical() const override;
    };

    class FlowContainer : public Container {
        private:
            FlowContainerNode* flowContainer = nullptr; // Pointer to the FlowContainer instance
            void connectContainerSignals() {
                // Connect signals specific to FlowContainer
            }

        public:
            FlowContainer() {
                setFlowContainer(memnew(FlowContainerProxy));
                onInit();
            }

            FlowContainer(FlowContainerNode* container) {
                setFlowContainer(container); 
            }

            FlowContainerNode* getContainer() {
                return flowContainer;
            }

            void setFlowContainer(FlowContainerNode* container) {
                this->flowContainer = container;
                connectContainerSignals();
                setContainer(container);
            }

            void setFlowContainer(FlowContainerProxy* container) {
                this->flowContainer = container;
                container->element = this;
                connectContainerSignals();
                setContainer(container);
            }
    };
}

#endif // !FLOW_CONTAINER_H