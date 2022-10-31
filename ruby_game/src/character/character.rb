class Character
    def initialize
        @w = 32
        @h = 32
        @x = @w / 2
        @y = @h / 2
        @speed = 32
        @image = Gosu::Image.new('src/images/Idle_D_1.png')
    end

    def draw
        @image.draw_rot(@x, @y, 0, 0)
    end

    def move_up
        @y -= @speed
    end

    def move_down
        @y += @speed
    end

    def move_left
        @x -= @speed
    end

    def move_right
        @x += @speed
    end
end