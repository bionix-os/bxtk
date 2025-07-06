package bxtk.ui;

@:native("SplitContainer")
extern class SplitContainer extends Container {
    public var collapsed: Bool;
    public var dragAreaHighlightInEditor: Bool;
    public var dragAreaMarginBegin: Int;
    public var dragAreaMarginEnd: Int;
    public var dragAreaOffset: Int;
    public var draggerVisibility: Int;
    public var draggingEnabled: Bool;
    public var splitOffset: Int;
    public var vertical: Bool;
    public var dragEnded: bxtk.core.Event;
    public var dragStarted: bxtk.core.Event;
    public var dragged: bxtk.core.Event;
    public function clanpSplitOffset(): Void;
    public function getDragAreaControl(): bxtk.ui.Control;
    @:native("cast")
    public static function toSplitContainer(obj: Dynamic): bxtk.ui.SplitContainer;
}

abstract SplitContainerAbstract(SplitContainer) from SplitContainer to SplitContainer {
    @:from
    public static function fromElement(element: bxtk.core.Element): bxtk.ui.SplitContainer {
        var splitContainer = bxtk.ui.SplitContainer.toSplitContainer(element);
        if (splitContainer.isNull()) {
            return null;
        }
        return splitContainer;
    }
}