import re

def splitFile(file):
    head, num = re.match(r'([a-z-. ]+)(\d{1,5})', file).groups()
    return[head, int(num)]

def solution(files):
    return sorted(files, key=lambda x: splitFile(x.lower()))



print(solution(["img12.png", 
                "img10.png",
                "img02.png",
                "img1.png",
                "IMG01.GIF",
                "img2.JPG"]))

print(solution(["F-15"]))