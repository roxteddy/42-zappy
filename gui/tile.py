import cocos
from cocos.actions import *
from conf import *
import pyglet.window.key as keys
import random

class Window(cocos.layer.Layer):
    is_event_handler = True
    scale = 1

    def __init__(self, x, y):
        super(Window, self).__init__()
        self.m = Map(x, y)
        self.print_tile()
        self.scene = cocos.scene.Scene(self)

    @staticmethod
    def _zoom_in(scale):
        if scale > 4: return scale
        else: return scale * 2.0

    @staticmethod
    def _zoom_out(scale):
        if scale < .01: return scale 
        else: return scale / 2.0

    def print_tile(self):
        z = -1
        z_ = -1
        for y in range(0, self.m.y):
            self.m.map.append([])
            for x in range(0, self.m.x):
                if random.randint(0, 7) == 3:
                    sprite2 = cocos.sprite.Sprite('cube.png')
                    sprite2.position = self.m.map_to_screen(x, y)
                    self.add(sprite2, z=z_)
                    z_ -= 1
                sprite = cocos.sprite.Sprite('tile.png')
                sprite.position = self.m.map_to_screen(x, y)
                self.add(sprite, z=z)
                self.m.map[y].append(sprite)
                z -= 1

    def on_key_release(self, key, modifiers):
        if key == keys.LEFT:
            self.scene.do(MoveBy((-20, 0), duration=0))
        elif key == keys.RIGHT:
            self.scene.do(MoveBy((20, 0), duration=0))
        elif key == keys.DOWN:
            self.scene.do(MoveBy((0, -20), duration=0))
        elif key == keys.UP:
            self.scene.do(MoveBy((0, 20), duration=0))

    def on_mouse_drag(self, x, y, dx, dy, buttons, modifiers):
        self.scene.do(MoveBy((dx, dy), duration=0))

    def on_mouse_scroll(self, x, y, dx, dy):
        if dy < 0:
            self.scale = self._zoom_out(self.scale)
            #self.parent.set_scale(self._desired_scale)
        elif dy > 0:
            self.scale = self._zoom_in(self.scale)
            #self.parent.set_scale(self._desired_scale)
        if dy:
            self.scene.do(ScaleTo(self.scale, .1))

class Map(object):
    def __init__(self, x, y):
        self.map = []
        self.x, self.y = x, y

    def map_to_screen(self, tile_x, tile_y):
        """ 2D isometric """
        screen_x = (tile_x - tile_y) * (tile_width / 2) + window_width / 2
        screen_y = (tile_x + tile_y) * (tile_height / 2)
        return (screen_x, screen_y)

    def screen_to_map(self, screen_x, screen_y):
        tile_x = (screen_x / (title_width / 2) + screen_y / (title_height / 2)) / 2
        tile_y = (screen_y / (title_height / 2) - (screen_x / (title_width / 2))) / 2
        return (tile_x, tile_y)


if __name__ == '__main__':
    cocos.director.director.init(window_width, window_height, do_not_scale=True)
    w = Window(15, 15)
#    main_scene.do(ScaleBy(0.5, duration=0))
    cocos.director.director.run(w.scene)
