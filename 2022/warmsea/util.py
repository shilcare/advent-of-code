import os


def get_input_lines(relative_to, filename):
    input_file = open(os.path.join(os.path.dirname(relative_to), filename))
    return list(map(lambda line: line.strip(), input_file.readlines()))


def list_split(input_list, separator):
    results = []
    length = len(input_list)
    start = 0
    while start < length:
        try:
            end = input_list.index(separator, start)
            results.append(input_list[start:end])
            start = end + 1
        except ValueError:
            results.append(input_list[start:])
            break
    return results


def get_input_sections(relative_to, filename):
    lines = get_input_lines(relative_to, filename)
    return list_split(lines, "")
