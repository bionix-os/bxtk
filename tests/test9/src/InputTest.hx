package;

import bxtk.Key;
import bxtk.core.Behavior;
import bxtk.input.InputService;

class InputTest extends Behavior{
    override function onUpdate(deltaTime: Float) : Void {
        if (InputService.isKeyPressed(Key.space)) {
            trace(deltaTime);
        }
    }

    override function onInit() {
    }
}