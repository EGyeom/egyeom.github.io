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

https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdna%2F0Er9f%2FdJMcadUAk4R%2FAAAAAAAAAAAAAAAAAAAAABtiKNljmgIvHbtABervnnraN3x8Pjz9hxjrXHOJZXW2%2Fimg.png%3Fcredential%3DyqXZFxpELC7KVnFOS48ylbz2pIh7yKj8%26expires%3D1761922799%26allow_ip%3D%26allow_referer%3D%26signature%3D310VO03INFciQrPXsuEDHUC8p1Y%253D

2\. System Properties 창에서 "Environment Variables..." 클릭.

[##_Image|kage@bawUKC/dJMcagqeUwW/AAAAAAAAAAAAAAAAAAAAAA1B0_gaILNnHvDQpT92Ce37rCrDfk15belAw1DFWy4E/img.png?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1761922799&amp;allow_ip=&amp;allow_referer=&amp;signature=GfrMHsgDBb6JoyHnqc2JCsNqQpI%3D|CDM|1.3|{"originWidth":464,"originHeight":522,"style":"alignCenter"}_##]

3\. User variables (또는 System variables)에서 Path 선택 → Edit → New → inkscape.exe가 있는 폴더 경로를 붙여넣기(예: C:\\Program Files\\Inkscape\\bin 또는 C:\\Program Files\\Inkscape) → 확인.

[##_Image|kage@X4Zbv/dJMcagKxFLR/AAAAAAAAAAAAAAAAAAAAAMkrHP_SMag_AQPfy-S7XEBirUUVJIG-yqWuW76I5O2L/img.png?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1761922799&amp;allow_ip=&amp;allow_referer=&amp;signature=E6qqqaf0Fbqr5VfdC5Ag2SPQc80%3D|CDM|1.3|{"originWidth":515,"originHeight":197,"style":"alignCenter"}_##]

참고: User PATH는 현재 사용자만 적용, System PATH는 모든 사용자(관리자 권한 필요).

cmd창을 껐다 키고, 아래 명령어를 쳐서 화면처럼 나오면 제대로 설정된거다

[##_Image|kage@mhQI4/dJMcajtJpZs/AAAAAAAAAAAAAAAAAAAAAOrS-o8OeCsusO0p3n-08rYqD_sGjctLr2yFRQ6rZEtI/img.png?credential=yqXZFxpELC7KVnFOS48ylbz2pIh7yKj8&amp;expires=1761922799&amp;allow_ip=&amp;allow_referer=&amp;signature=TNE07mSL4HbVLSo2aPyB6JJEjlU%3D|CDM|1.3|{"originWidth":508,"originHeight":128,"style":"alignCenter"}_##]

이제 사용하는 방법은 cmd 환경에서 아래처럼 명령어를 치면 된다.

```
inkscape "C:\path\to\mmu_overview.svg" --export-type=png --export-filename="C:\path\to\mmu_overview_1200x630.png" -w 1200 -h 630
```

모두 블로그 파이팅 하시길 !!
