require 'gosu'
require './src/map/map.rb'
require './src/map/elements.rb'
require './src/character/character.rb'


    
class Game < Gosu::Window
    def initialize
        @map = Map.new
        @char = Character.new
        @width = @map.getWidth * 32
        @height = @map.getHeight * 32
        super @width, @height, false
    end
    
    def update
    end
    
    def draw
        @map.printMap
        @char.draw
    end
    
    def button_down(id) 
        case id
            when Gosu::KbEscape 
                close 
            # when Gosu::KB_SPACE
            #     @char.move
            when Gosu::KB_LEFT
                @char.move_left
            when Gosu::KB_RIGHT
                @char.move_right
            when Gosu::KB_UP
                @char.move_up
            when Gosu::KB_DOWN
                @char.move_down
        end 
    end

    def button_up(id)

    end

end

Game.new.show