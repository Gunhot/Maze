OpenFramework로 만든 미로를 제작하고 최단 경로를 찾는 프로그램입니다.
미로를 제작하는데는 Eller's Algorithm을 사용하였고,
DFS와 BFS를 사용해서 최단경로를 찾아보았습니다.

maze.c는 미로를 생성하는 c언어 파일입니다.
maze.maz는 maze.c를 통해 생성한 미로 파일입니다.

ofApp.cpp, ofApp.h ofxWinMenu.h ofxWinMenu.cpp는 OpenFramework 내에서 작동합니다.
examples 폴더에 들어간다. -> templates 폴더에 들어간다. -> emptyExample에 들어간다.

src폴더에 ofApp.cpp ofApp.h ofxWinMenu.h ofxWinMenu.cpp를 복사해서 덮어쓴다.
bin 폴더에 들어간다. maze.maz를 복사붙여넣기한다. -> data 폴더에 들어간다. maze.maz를 복사붙여넣기한다.

솔루션을 열고 build 후 run한다.
File -> maze.maz 선택!
