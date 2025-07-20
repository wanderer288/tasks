
import json, sys

if len(sys.argv) != 4:
    print("Использование: python script.py values.txt tests.txt report.txt")
    sys.exit(1)

v_path, t_path, r_path = sys.argv[1:]

# открытие файла values
try:
    with open(v_path, encoding='utf-8') as f:
        vals = json.load(f)
    print(f'Файл "{v_path}" успешно открыт')
except:
    print(f'Ошибка открытия "{v_path}"')
    sys.exit(1)

# открытие файла tests
try:
    with open(t_path, encoding='utf-8') as f:
        tests = json.load(f)
    print(f'Файл "{t_path}" успешно открыт')
except:
    print(f'Ошибка открытия "{t_path}"')
    sys.exit(1)

# создание словаря
d = { item["id"]: item["value"] for item in vals.get("values", []) }

# заполнение файла
def fill(node):
    if "id" in node:
        node["value"] = d.get(node["id"], "")
    for child in node.get("values", []):
        fill(child)

for t in tests.get("tests", []):
    fill(t)


try:
    with open(r_path, "w", encoding='utf-8') as f:
        json.dump(tests, f, ensure_ascii=False, indent=2)
    print(f'Файл "{r_path}" успешно открыт')
except:
    print(f'Ошибка открытия "{r_path}"')
    sys.exit(1)
