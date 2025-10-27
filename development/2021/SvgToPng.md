블로그를 작성할때 Svg 파일을 Png 파일로 바꿔서 업로드 하는것이 편하다.

그 중 윈도우 환경에서 Inkscape를 사용하는 방법을 소개하겠다.

**Windows 기준**

관리자 권한 PowerShell/명령 프롬프트에서

```
winget install --id Inkscape.Inkscape -e --source winget
```

이렇게 설치하게 되면, 경로는 보통

C:\\Program Files\\Inkscape\\inkscape.exe

C:\\Program Files\\Inkscape\\bin\\inkscape.exe

에 위치하게 된다.

사용하려면 "C:\\Program Files\\Inkscape\\inkscape.exe" 이렇게 쳐줘야 하기때문에 너무 귀찮으므로

경로 설정을 해주자.

exe가 있는 폴더(예: C:\\Program Files\\Inkscape 또는 C:\\Program Files\\Inkscape\\bin)를 PATH에 추가해야 한다.

**GUI(환경 변수 편집)로 추가하는 방법**

1\. Windows 키 → "환경 변수 편집" 또는 "Edit the system environment variables" 실행
<img width="742" height="300" alt="image" src="https://github.com/user-attachments/assets/29fc2000-6194-4b86-b453-554e7dd85d4f" />

2\. System Properties 창에서 "Environment Variables..." 클릭.

<img width="464" height="522" alt="image" src="https://github.com/user-attachments/assets/cc27def7-893c-4fe4-bd95-95fbad7e5858" />

3\. User variables (또는 System variables)에서 Path 선택 → Edit → New → inkscape.exe가 있는 폴더 경로를 붙여넣기(예: C:\\Program Files\\Inkscape\\bin 또는 C:\\Program Files\\Inkscape) → 확인.

<img width="515" height="197" alt="image" src="https://github.com/user-attachments/assets/ac7f4bde-9121-4a81-b4ea-7d6b9271c9cb" />

참고: User PATH는 현재 사용자만 적용, System PATH는 모든 사용자(관리자 권한 필요).

cmd창을 껐다 키고, 아래 명령어를 쳐서 화면처럼 나오면 제대로 설정된거다

<img width="508" height="128" alt="image" src="https://github.com/user-attachments/assets/2c26d8de-472d-4b26-b10c-988720a0bce1" />

이제 사용하는 방법은 cmd 환경에서 아래처럼 명령어를 치면 된다.

```
inkscape "C:\path\to\mmu_overview.svg" --export-type=png --export-filename="C:\path\to\mmu_overview_1200x630.png" -w 1200 -h 630
```

모두 블로그 파이팅 하시길 !!
