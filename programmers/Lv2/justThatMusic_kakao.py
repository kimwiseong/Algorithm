def deleteSharp(s):
    return s.replace('C#', 'c').replace('D#', 'd').replace('F#', 'f').replace('G#', 'g').replace('A#', 'a').replace('E#', 'e')

def getTime(time):
    hh, mm = time.split(":")
    hh, mm = int(hh), int(mm)
    if hh < 0: hh += 24
    return hh * 60 + mm

def solution(m, musicinfos):
    answer, musics = [], {}
    m = deleteSharp(m)
    
    for i in musicinfos:
        start, end, title, melody = i.split(",")
        melody = deleteSharp(melody)
        runtime = getTime(end) - getTime(start)
        musics[melody*(runtime//len(melody))+melody[:runtime % len(melody)]] = [title, runtime]
    
    for music in musics:
        if m in music: answer.append(musics[music])
    
    answer.sort(key=lambda x : x[1], reverse=True)
    return  answer[0][0] if answer else "(None)"


print(solution("ABCDEFG", ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
print(solution("CC#BCC#BCC#BCC#B", ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]))
print(solution("AAA", ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]))
