defmodule AdventOfCodeDayOne do
  def solve_part1(path) do
    File.stream!(path)
    |> Enum.reduce({[], []}, fn line, {list1, list2} ->
       [val1, val2] = String.split(line) |> Enum.map(&String.to_integer/1)
       {[val1 | list1], [val2 | list2]}
    end) |> then(fn {list1, list2} ->
      Enum.zip(Enum.sort(list1), Enum.sort(list2))
      |> Enum.reduce(0, fn {val1, val2}, acc ->
        acc + abs(val1 - val2)
      end)
    end)
  end

  def solve_part2(path) do
    File.stream!(path)
    |> Enum.reduce({[], []}, fn line, {list1, list2} ->
      [val1, val2] = String.split(line) |> Enum.map(&String.to_integer/1)
      {[val1 | list1], [val2 | list2]}
    end) |> then(fn {list1, list2} ->
      counts = Enum.frequencies(list2)
      list1 |> Enum.reduce(0, fn num, total ->
        total + num * Map.get(counts, num, 0)
      end)
    end)
  end
end

IO.puts AdventOfCodeDayOne.solve_part1("dayone.txt")
IO.puts AdventOfCodeDayOne.solve_part2("dayone.txt")
