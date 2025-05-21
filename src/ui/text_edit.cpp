#include "text_edit.h"

namespace sunaba::ui {
    void TextEditProxy::_enter_tree() {
        if (this->element != nullptr) {
            this->element->enterTree();
        }
    }

    void TextEditProxy::_exit_tree() {
        if (this->element != nullptr) {
            this->element->exitTree();
        }
    }

    void TextEditProxy::_ready() {
        if (this->element != nullptr) {
            this->element->ready();
        }
    }

    void TextEditProxy::_process(double delta) {
        if (this->element != nullptr) {
            this->element->process(delta);
        }
    }

    void TextEditProxy::_physics_process(double delta) {
        if (this->element != nullptr) {
            this->element->physicsProcess(delta);
        }
    }

    void TextEditProxy::_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->input(event);
        }
    }

    void TextEditProxy::_unhandled_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledInput(event);
        }
    }

    void TextEditProxy::_unhandled_key_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->unhandledKeyInput(event);
        }
    }

    void TextEditProxy::_shortcut_input(const Ref<InputEvent>& event) {
        if (this->element != nullptr) {
            this->element->shortcutInput(event);
        }
    }

    void TextEditProxy::_draw() {
        if (this->element != nullptr) {
            this->element->_draw();
        }
    }

    bool TextEditProxy::_can_drop_data(const Vector2& at_position, const Variant &data) const {
        if (this->element != nullptr) {
            return this->element->canDropData(at_position, data);
        }
        return false;
    }

    void TextEditProxy::_drop_data(const Vector2 &at_position, const Variant &data) {
        if (this->element != nullptr) {
            this->element->dropData(at_position, data);
        }
    }

    Variant TextEditProxy::_get_drag_data(const Vector2 &at_position) {
        if (this->element != nullptr) {
            return this->element->getDragData(at_position);
        }
        return Variant();
    }

    Vector2 TextEditProxy::_get_minimum_size() const {
        if (this->element != nullptr) {
            return this->element->_getMinimumSize();
        }
        return Vector2();
    }

    String TextEditProxy::_get_tooltip(const Vector2 &at_position) const {
        if (this->element != nullptr) {
            return this->element->_getTooltip(at_position).c_str();
        }
        return String();
    }

    void TextEditProxy::_gui_input(const Ref<InputEvent> &event) {
        if (this->element != nullptr) {
            this->element->guiInput(event);
        }
    }

    bool TextEditProxy::_has_point(const Vector2 &point) const {
        if (this->element != nullptr) {
            return this->element->hasPoint(point);
        }
        return false;
    }

    TypedArray<Vector3i> TextEditProxy::_structured_text_parser(const Array &args, const String &text) const {
        if (this->element != nullptr) {
            return this->element->structuredTextParser(args, text);
        }
        return TypedArray<Vector3i>();
    }

    void TextEditProxy::_backspace(int caret_index) {
        if (this->element != nullptr) {
            this->element->onBackspace(caret_index);
        }
    }

    void TextEditProxy::_copy(int caret_index) {
        if (this->element != nullptr) {
            this->element->onCopy(caret_index);
        }
    }

    void TextEditProxy::_cut(int caret_index) {
        if (this->element != nullptr) {
            this->element->onCut(caret_index);
        }
    }

    void TextEditProxy::_handle_unicode_input(int unicode_char, int caret_index) {
        if (this->element != nullptr) {
            this->element->onHandleUnicodeInput(unicode_char, caret_index);
        }
    }

    void TextEditProxy::_paste(int caret_index) {
        if (this->element != nullptr) {
            this->element->onPaste(caret_index);
        }
    }

    void TextEditProxy::_paste_primary_clipboard(int caret_index) {
        if (this->element != nullptr) {
            this->element->onPastePrimaryClipboard(caret_index);
        }
    }

    void bindTextEdit(sol::state& lua) {
        lua.new_usertype<TextEdit>("TextEdit",
            sol::constructors<TextEdit()>(),
            sol::base_classes, sol::bases<BaseObject, Element, sunaba::core::CanvasItem, Control>(),
            "autowrapMode", sol::property(
                &TextEdit::getAutowrapMode,
                &TextEdit::setAutowrapMode
            ),
            "caretBlink", sol::property(
                &TextEdit::getCaretBlink,
                &TextEdit::setCaretBlink
            ),
            "caretBlinkInterval", sol::property(
                &TextEdit::getCaretBlinkInterval,
                &TextEdit::setCaretBlinkInterval
            ),
            "caretDrawWhenEditableDisabled", sol::property(
                &TextEdit::getCaretDrawWhenEditableDisabled,
                &TextEdit::setCaretDrawWhenEditableDisabled
            ),
            "caretMidGrapheme", sol::property(
                &TextEdit::getCaretMidGrapheme,
                &TextEdit::setCaretMidGrapheme
            ),
            "caretMoveOnRightClick", sol::property(
                &TextEdit::getCaretMoveOnRightClick,
                &TextEdit::setCaretMoveOnRightClick
            ),
            "caretMultiple", sol::property(
                &TextEdit::getCaretMultiple,
                &TextEdit::setCaretMultiple
            ),
            "caretType", sol::property(
                &TextEdit::getCaretType,
                &TextEdit::setCaretType
            ),
            "clipContents", sol::property(
                &TextEdit::getClipContents,
                &TextEdit::setClipContents
            ),
            "contextMenuEnabled", sol::property(
                &TextEdit::getContextMenuEnabled,
                &TextEdit::setContextMenuEnabled
            ),
            "customWordSeparators", sol::property(
                &TextEdit::getCustomWordSeparators,
                &TextEdit::setCustomWordSeparators
            ),
            "deselectOnFocusLossEnabled", sol::property(
                &TextEdit::getDeselectOnFocusLossEnabled,
                &TextEdit::setDeselectOnFocusLossEnabled
            ),
            "dragAndDropSelectionEnabled", sol::property(
                &TextEdit::getDragAndDropSelectionEnabled,
                &TextEdit::setDragAndDropSelectionEnabled
            ),
            "drawControlChars", sol::property(
                &TextEdit::getDrawControlChars,
                &TextEdit::setDrawControlChars
            ),
            "drawSpaces", sol::property(
                &TextEdit::getDrawSpaces,
                &TextEdit::setDrawSpaces
            ),
            "drawTabs", sol::property(
                &TextEdit::getDrawTabs,
                &TextEdit::setDrawTabs
            ),
            "editable", sol::property(
                &TextEdit::getEditable,
                &TextEdit::setEditable
            ),
            "emojiMenuEnabled", sol::property(
                &TextEdit::getEmojiMenuEnabled,
                &TextEdit::setEmojiMenuEnabled
            ),
            "emptySelectionClipboardEnabled", sol::property(
                &TextEdit::getEmptySelectionClipboardEnabled,
                &TextEdit::setEmptySelectionClipboardEnabled
            ),
            "focusMode", sol::property(
                &TextEdit::getFocusMode,
                &TextEdit::setFocusMode
            ),
            "highlightAllOccurrences", sol::property(
                &TextEdit::getHighlightAllOccurrences,
                &TextEdit::setHighlightAllOccurrences
            ),
            "highlightCurrentLine", sol::property(
                &TextEdit::getHighlightCurrentLine,
                &TextEdit::setHighlightCurrentLine
            ),
            "indentWrappedLines", sol::property(
                &TextEdit::getIndentWrappedLines,
                &TextEdit::setIndentWrappedLines
            ),
            "language", sol::property(
                &TextEdit::getLanguage,
                &TextEdit::setLanguage
            ),
            "middleMousePasteEnabled", sol::property(
                &TextEdit::getMiddleMousePasteEnabled,
                &TextEdit::setMiddleMousePasteEnabled
            ),
            "minimapDraw", sol::property(
                &TextEdit::getMinimapDraw,
                &TextEdit::setMinimapDraw
            ),
            "minimapWidth", sol::property(
                &TextEdit::getMinimapWidth,
                &TextEdit::setMinimapWidth
            ),
            "mouseDefaultCursorShape", sol::property(
                &TextEdit::getMouseDefaultCursorShape,
                &TextEdit::setMouseDefaultCursorShape
            ),
            "placeholderText", sol::property(
                &TextEdit::getPlaceholderText,
                &TextEdit::setPlaceholderText
            ),
            "scrollFitContentHeight", sol::property(
                &TextEdit::getScrollFitContentHeight,
                &TextEdit::setScrollFitContentHeight
            ),
            "scrollFitContentWidth", sol::property(
                &TextEdit::getScrollFitContentWidth,
                &TextEdit::setScrollFitContentWidth
            ),
            "scrollHorizontal", sol::property(
                &TextEdit::getScrollHorizontal,
                &TextEdit::setScrollHorizontal
            ),
            "scrollPastEndOfFile", sol::property(
                &TextEdit::getScrollPastEndOfFile,
                &TextEdit::setScrollPastEndOfFile
            ),
            "scrollSmooth", sol::property(
                &TextEdit::getScrollSmooth,
                &TextEdit::setScrollSmooth
            ),
            "scrollVScrollSpeed", sol::property(
                &TextEdit::getScrollVScrollSpeed,
                &TextEdit::setScrollVScrollSpeed
            ),
            "scrollVertical", sol::property(
                &TextEdit::getScrollVertical,
                &TextEdit::setScrollVertical
            ),
            "selectingEnabled", sol::property(
                &TextEdit::getSelectingEnabled,
                &TextEdit::setSelectingEnabled
            ),
            "shortcutKeysEnabled", sol::property(
                &TextEdit::getShortcutKeysEnabled,
                &TextEdit::setShortcutKeysEnabled
            ),
            "structuredTextBidiOverride", sol::property(
                &TextEdit::getStructuredTextBidiOverride,
                &TextEdit::setStructuredTextBidiOverride
            ),
            "structuredTextBidiOverrideOptions", sol::property(
                &TextEdit::getStructuredTextBidiOverrideOptions,
                &TextEdit::setStructuredTextBidiOverrideOptions
            ),
            "syntaxHighlighter", sol::property(
                &TextEdit::getSyntaxHighlighter,
                &TextEdit::setSyntaxHighlighter
            ),
            "text", sol::property(
                &TextEdit::getText,
                &TextEdit::setText
            ),
            "textDirection", sol::property(
                &TextEdit::getTextDirection,
                &TextEdit::setTextDirection
            ),
            "useCustomWordSeparators", sol::property(
                &TextEdit::getUseCustomWordSeparators,
                &TextEdit::setUseCustomWordSeparators
            ),
            "useDefaultWordSeparators", sol::property(
                &TextEdit::getUseDefaultWordSeparators,
                &TextEdit::setUseDefaultWordSeparators
            ),
            "virtualKeyboardEnabled", sol::property(
                &TextEdit::getVirtualKeyboardEnabled,
                &TextEdit::setVirtualKeyboardEnabled
            ),
            "wrapMode", sol::property(
                &TextEdit::getWrapMode,
                &TextEdit::setWrapMode
            ),
            "caretChanged", sol::property(
                &TextEdit::getCaretChangedEvent,
                &TextEdit::setCaretChangedEvent
            ),
            "gutterAdded", sol::property(
                &TextEdit::getGutterAddedEvent,
                &TextEdit::setGutterAddedEvent
            ),
            "gutterClicked", sol::property(
                &TextEdit::getGutterClickedEvent,
                &TextEdit::setGutterClickedEvent
            ),
            "gutterRemoved", sol::property(
                &TextEdit::getGutterRemovedEvent,
                &TextEdit::setGutterRemovedEvent
            ),
            "linesEditedFrom", sol::property(
                &TextEdit::getLinesEditedFromEvent,
                &TextEdit::setLinesEditedFromEvent
            ),
            "textChanged", sol::property(
                &TextEdit::getTextChangedEvent,
                &TextEdit::setTextChangedEvent
            ),
            "textSet", sol::property(
                &TextEdit::getTextSetEvent,
                &TextEdit::setTextSetEvent
            ),
            "addCaret", &TextEdit::addCaret,
            "addCaretAtCarets", &TextEdit::addCaretAtCarets,
            "addGutter", &TextEdit::addGutter,
            "addSelectionForNextOccurrence", &TextEdit::addSelectionForNextOccurrence,
            "adjustCaretsAfterEdit", &TextEdit::adjustCaretsAfterEdit,
            "adjustViewportToCaret", &TextEdit::adjustViewportToCaret,
            "applyIme", &TextEdit::applyIme,
            "backspace", &TextEdit::backspace,
            "beginComplexOperation", &TextEdit::beginComplexOperation,
            "beginMulticaretEdit", &TextEdit::beginMulticaretEdit,
            "cancelIme", &TextEdit::cancelIme,
            "centerViewportToCaret", &TextEdit::centerViewportToCaret,
            "clear", &TextEdit::clear,
            "collapseCarets", &TextEdit::collapseCarets,
            "copy", &TextEdit::copy,
            "cut", &TextEdit::cut,
            "deleteSelection", &TextEdit::deleteSelection,
            "deselect", &TextEdit::deselect,
            "endAction", &TextEdit::endAction,
            "endComplexOperation", &TextEdit::endComplexOperation,
            "endMulticaretEdit", &TextEdit::endMulticaretEdit,
            "getCaretColumn", &TextEdit::getCaretColumn,
            "getCaretCount", &TextEdit::getCaretCount,
            "getCaretDrawPos", &TextEdit::getCaretDrawPos,
            "getCaretIndexEditOrder", &TextEdit::getCaretIndexEditOrder,
            "getCaretLine", &TextEdit::getCaretLine,
            "getCaretWrapIndex", &TextEdit::getCaretWrapIndex,
            "getFirstNonWhitespaceColumn", &TextEdit::getFirstNonWhitespaceColumn,
            "getFirstVisibleLine", &TextEdit::getFirstVisibleLine,
            "getGutterCount", &TextEdit::getGutterCount,
            "getGutterName", &TextEdit::getGutterName,
            "getGutterType", &TextEdit::getGutterType,
            "getGutterWidth", &TextEdit::getGutterWidth,
            "getHScrollBar", &TextEdit::getHScrollBar,
            "getIndentLevel", &TextEdit::getIndentLevel,
            "getLastFullVisibleLine", &TextEdit::getLastFullVisibleLine,
            "getLastFullVisibleLineWrapIndex", &TextEdit::getLastFullVisibleLineWrapIndex,
            "getLastUnhiddenLine", &TextEdit::getLastUnhiddenLine,
            "getLine", &TextEdit::getLine,
            "getLineBackgroundColor", &TextEdit::getLineBackgroundColor,
            "getLineColumnAtPos", &TextEdit::getLineColumnAtPos,
            "getLineCount", &TextEdit::getLineCount,
            "getLineGutterIcon", &TextEdit::getLineGutterIcon,
            "getLineGutterItemColor", &TextEdit::getLineGutterItemColor,
            "getLineGutterMetadata", &TextEdit::getLineGutterMetadata,
            "getLineGutterText", &TextEdit::getLineGutterText,
            "getLineHeight", &TextEdit::getLineHeight,
            "getLineRangesFromCarets", &TextEdit::getLineRangesFromCarets,
            "getLineWidth", &TextEdit::getLineWidth,
            "getLineWithIme", &TextEdit::getLineWithIme,
            "getLineWrapCount", &TextEdit::getLineWrapCount,
            "getLineWrapIndexAtColumn", &TextEdit::getLineWrapIndexAtColumn,
            "getLineWrappedText", &TextEdit::getLineWrappedText,
            "getLocalMousePos", &TextEdit::getLocalMousePos,
            "getMenu", &TextEdit::getMenu,
            "getMinimapLineAtPos", &TextEdit::getMinimapLineAtPos,
            "getMinimapVisibleLines", &TextEdit::getMinimapVisibleLines,
            "getNextVisibleLineIndexOffsetFrom", &TextEdit::getNextVisibleLineIndexOffsetFrom,
            "getNextVisibleLineOffsetFrom", &TextEdit::getNextVisibleLineOffsetFrom,
            "getPosAtLineColumn", &TextEdit::getPosAtLineColumn,
            "getRectAtLineColumn", &TextEdit::getRectAtLineColumn,
            "getSavedVersion", &TextEdit::getSavedVersion,
            "getScrollPosForLine", &TextEdit::getScrollPosForLine,
            "getSelectedText", &TextEdit::getSelectedText,
            "getSelectionAtLineColumn", &TextEdit::getSelectionAtLineColumn,
            "getSelectionColumn", &TextEdit::getSelectionColumn,
            "getSelectionFromColumn", &TextEdit::getSelectionFromColumn,
            "getSelectionFromLine", &TextEdit::getSelectionFromLine,
            "getSelectionLine", &TextEdit::getSelectionLine,
            "getSelectionMode", &TextEdit::getSelectionMode,
            "getSelectionOriginColumn", &TextEdit::getSelectionOriginColumn,
            "getSelectionOriginLine", &TextEdit::getSelectionOriginLine,
            "getSelectionToColumn", &TextEdit::getSelectionToColumn,
            "getSelectionToLine", &TextEdit::getSelectionToLine,
        );
    }
}