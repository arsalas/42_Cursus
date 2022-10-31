class Grass
    def initialize(x, y)
        @w = 32
        @h = 32
        @x = @w / 2 + x * 32 
        @y = @h / 2 + y * 32
        @image = Gosu::Image.new('src/images/grass.png')
        @image.draw_rot(@x, @y, 0, 0)
    end

    def draw
        @image.draw_rot(@x, @y, 0, 0)
    end

end

class Wall
    def initialize(x, y)
        @w = 32
        @h = 32
        @x = @w / 2 + x * 32 
        @y = @h / 2 + y * 32
        @image = Gosu::Image.new('src/images/wall2.png')
        @image.draw_rot(@x, @y, 0, 0)
    end

    def draw
        @image.draw_rot(@x, @y, 0, 0)
    end

end
