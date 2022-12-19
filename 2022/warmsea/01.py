import util


def p1():
    input_sections = util.get_input_sections(__file__, "01.input")
    summaries = map(lambda section: sum(map(int, section)), input_sections)
    return max(summaries)


def p2():
    input_sections = util.get_input_sections(__file__, "01.input")
    summaries = map(lambda section: sum(map(int, section)), input_sections)
    return sum(sorted(summaries)[-3:])


if __name__ == "__main__":
    print(p1())
    print(p2())
