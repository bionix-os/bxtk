package;

import bxtk.input.InputEvent;
import bxtk.App;
import bxtk.core.Scene;
import bxtk.core.SceneManager;
import bxtk.core.Entity;

class Main extends App{
    public static function main() {
        new Main();
    }

    override function init() {
        try {
            var sceneManager = new SceneManager();
            rootElement.addChild(sceneManager);
            var scene : Scene = sceneManager.scene;
            var entity : Entity = new Entity();
            entity.name = "Entity";
            scene.addEntity(entity);
            var inputTest = new InputTest();
            entity.addComponent(inputTest.component, "InputTest");
        }
        catch( e: Dynamic) {
            trace(e);
        }
    }
}