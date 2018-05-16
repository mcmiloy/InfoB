class Fridge

    def initialize(items)
        @items = items
    end

    def buy_things()
        loop do
            puts "Do you want to buy more(Yes/No): "
            keep_buying = gets.chomp
            break unless keep_buying=="Yes"

            puts "What kind of stuff do you want: "
            @items.each_key {|key| print key.to_s + ", "}
            print ": "
            input_category = gets.chomp.to_sym
            if !(@items.key?(input_category))
                puts "That category doesn't exist"
                next
            end

            puts "What exactly do yo want: "
            @items[input_category].each_pair {|key, value| print key.to_s + ": " + value.to_s + ", " unless key=="LIMIT"}
            print ": "            
            input_product = gets.chomp.to_sym
            if !(@items[input_category].key?(input_product))
                puts "That product doesn't exist"
                next
            end

            puts "How much do you want to buy: "
            input_amout = gets.chomp.to_i
            if (@items[input_category][input_product] + input_amout) > @items[input_category]["LIMIT"]
                puts "The fridge will fit more than #{@items[input_category]["LIMIT"]} #{@items[input_category].to_s}"
                next
            else
                @items[input_category][input_product] += input_amout
            end

        end
        puts "You have: "
        puts
        show_items
    end

    def show_items()
        @items.each_key do |key|
            puts "#{key.to_s}: "
            @items[key].each_pair do |inner_key, inner_value|
                print "#{inner_key.to_s}: #{inner_value}, " unless inner_key=="LIMIT"
            end
            puts
        end
    end


end


# Buy what kind of stuff:
# Buy what exactly:
# Buy how much:

myfridge_init = {Beverages: {Coke: 0,
                             Mate: 0,
                             Water: 0,
                             Beer: 0,
                             "LIMIT" => 10},
                 Sweets: {GummyBears: 0,
                          Chocolate: 0,
                          ChewingGum: 0,
                          "LIMIT" => 10}}

myfridge = Fridge.new(myfridge_init)
myfridge.buy_things

