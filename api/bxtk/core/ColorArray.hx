package bxtk.core;

import bxtk.core.Color;

abstract ColorArray(lua.Table<Int, Color>) from lua.Table<Int, Color> to lua.Table<Int, Color> {
    @:to
    public inline function toArray(): Array<Color> {
        var table : lua.Table<Int, Color> = this;
        return lua.Table.toArray(table);
    }

    @:from
    public static function fromArray(array: Array<Color>): ColorArray {
        var result = lua.Table.fromArray(array);
        return result;
    }
}