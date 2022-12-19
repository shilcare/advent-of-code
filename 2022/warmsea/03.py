import functools

import util


def get_priority(item):
    if "a" <= item <= "z":
        return ord(item) - ord("a") + 1
    else:  # "A" <= item <= "Z"
        return ord(item) - ord("A") + 27


def p1():
    input_lines = util.get_input_lines(__file__, "03.input")
    result = 0
    for line in input_lines:
        middle = int(len(line) / 2)
        common = set(line[:middle]).intersection(set(line[middle:])).pop()  # assuming exact one item
        result += get_priority(common)
    return result


def p2():
    input_lines = util.get_input_lines(__file__, "03.input")
    result = 0
    for index in range(0, len(input_lines), 3):
        group = map(set, input_lines[index:index + 3])
        common = functools.reduce(lambda a, b: a.intersection(b), group).pop()  # assuming exact one item
        result += get_priority(common)
    return result


if __name__ == "__main__":
    print(p1())
    print(p2())
