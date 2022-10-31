
class Map
    def initialize
        @data = []
        self.read
    end

    def read
        file = File.open("./src/maps/001")
        file_data = file.read
        aux = file_data.split("\n");
        aux.each_with_index do |line, i|
           @data[i] = line.chars
        end
    end

    def getWidth
        return @data[0].length
    end

    def getHeight
        return @data.length
    end

    def printMap
        @data.each_with_index do |rowY, y|
            @data[y].each_with_index do |rowX, x|
                if @data[y][x] == "0"
                    Grass.new(x, y)
                else
                    Wall.new(x, y)
                end
            end
        end
    end
    
end