defmodule AdventOfCodeDayTwo do
  def task(input) do
    parse = fn input ->
      input
      |> String.split("\n", trim: true)
      |> Enum.map(fn line ->
        line
        |> String.split(" ")
        |> Enum.map(&String.trim/1)
        |> Enum.map(&String.to_integer/1)
      end)
    end

    validate = fn list, _ ->
      monotonic? = fn list ->
        Enum.all?(Enum.zip(list, Enum.drop(list, 1)), fn {a, b} -> a <= b end) or
        Enum.all?(Enum.zip(list, Enum.drop(list, 1)), fn {a, b} -> a >= b end)
      end

      valid_diff? = fn list ->
        Enum.chunk_every(list, 2, 1, :discard)
        |> Enum.all?(fn [a, b] ->
          diff = abs(a - b)
          diff > 0 and diff < 4
        end)
      end

      monotonic?.(list) and valid_diff?.(list)
    end

    input
    |> parse.()
    |> Enum.map(&validate.(&1, validate))
    |> Enum.count(& &1)
  end
end

{:ok, contents} = File.read("daytwo.txt")

IO.puts("Strict Safe Count: #{AdventOfCodeDayTwo.task(contents)}")
