# CleanCodeStudy
Clean code study
  
  
  
## 1장 : 깨끗한 코드

>르블랑의 법칙: 나중은 결코 오지 않는다.
나쁜 코드는 개발속도 저하 및 생산성을 낮춤. 
깨끗한 코드를 만드는 노력을, 개발 초기부터 하도록 한다.



### 깨끗한 코드를 어떻게 작성하고 유지하는가?
 ***1) 코드감각을 키운다 =>***  좋은코드와 나쁜코드를 많이 보도록 한다.\
 ***2) 절제와 규율을 적용한다 =>*** 다양한 방법이 존재하므로 규칙을 정하도록 하자

### 깨끗한 코드란?
1) 보기에 즐거운 코드, 효율중시(속도 및 자원)
2) 오류처리가 세세하게 되어있으며 (메모리 누수, 경쟁상태, 일관성 없는 명명법은 좋지 않음), 한가지 일을 잘 함
3) 가독성이 높음 (명료하고 구체적으로 작성)
4) 다른사람이 고치기 쉬운 코드, 작은 구성
5) 주의깊게 코드를 작성, 항상 깔끔하고 단정하게 작성
6) 코드 규칙을 잘 지킴
 - 모든 Test들을 통과하고, 중복이 최소한이며, 문제의 idea에 집중하여 (함수,변수 등을) 명확히 표현, 집합을 추상화 (공통적 요소들을 추출)
7) 짐작했던 기능이 그대로 수행되어야 함. (코드 독해에 문제가 있어선 안됨. 단순하게!)
 
### 저자의 생각
 >보이스카우트 규칙 : 체크아웃할 때보다 좀 더 깨끗한 상태로 체크인
 >프리퀼과 원칙 (Principles, patterns, and practices )
 결국, 평소 꾸준히 꺠끗한 코드를 만들도록 연습해야 함 
   
  
  
## 2장 : 의미있는 이름
1. 의도를 분명히 밝히기
 - 3Q : 존재이유? 수행기능? 사용방법?
 - 주석이 필요 없는 코드가 되도록
2. 그릇된 정보를 피하기
 - 약어, 오해요지 있는 이름, 유사 표기어는 피하자
3. 의미있게 구분
 - 불용어를 피하자 : 테이블 변수를 알려줄 필요가 없는데 xxxTable이라고 이름을 짓거나 수량이 중요하지 않은 변수명에 a,an,the를 붙이지 않는다
4. 발음하기 쉬운 이름 사용
5. 검색하기 쉬운 이름 사용
 - IDE를 사용하여 검색하기 쉬운 이름
 - 이름길이가 범위의 크기와 비례하는 것을 권장 
6. 인코딩을 피하자
 - 이름에 인코딩 관련 정보/멤버 변수 접두어 정보를 넣을 필요 없음
 - 인터페이스 vs 구현 클래스, 구현 클래스를 인코딩 하도록 한다 (XXXImpl)
7. 기억력을 자랑하지 말자
 - 클래스/객체 이름: 명사,명사구
 - 메서드 이름: 동사, 동사구
 ```
 Class(O): Customer, Wikipage, Account, AddressParser...
 Class(X): Manager, Processor, Data, Info...
 Method(O): postPayment, deletePage, saveXXX, isXXX...
 ```
8. 기발한 이름은 피하자
9. 한 개념에 한 단어를 사용하자
10. 말장난은 사용하지 않는다
 - 서로 같은 많은 단어들을 일관성 있게 사용하되, 동작이 다르면 구분을 하도록 한다
```
addXX 함수들이 항목들을 더해 새로운 값을 반환한다면, 집합에 값 하나를 추가하는 함수는 insertXXX
```
11. 해법 영역에서 가져온 이름을 사용하되, 적절한 이름이 없을 경우 문제영역에서 가져온 이름을 사용하도록 한다
 -코드를 읽는 사람은 개발자 일 것이다
12. 의미있는 맥락을 추가하고 불필요한 맥락을 없앤다





## 3장 : 함수

### 함수 만들기 규칙?
1) 함수를 작게 만들기: 블록과 들여쓰기가 적게!
2) 한가지만을 "잘" 하게 만들기
 - 함수내 추상화 수준(블록 나눔)이 한 단계로만 수행되어야 함
3) 함수당 추상화 수준이 섞이지 않게, 내려가기 규칙을 따르기
 - 내려가기 규칙: 위->아래 순서로, 추상화 단계(함수) 배치. 이야기를 읽듯이
4) Switch문은 다형성을 이용
 - Switch문은 변경 가능성을 고려하라
5) 서술적인 이름을 사용하라
 - 함수명에 일관성이 있어야 함. 같은 모듈 내에선 같은 문구,명사,동사를 사용한다
6) 함수 인수 : 인수와 함수명은 추상화 레벨이 달라 함수의 개념을 이해하기 어렵게 만듦
 - 이상적인 인수갯수: 0개
 - 많이쓰는 단항 형식:
  (1) 인수에 질문을 던지는 경우
  ```
  boolean fileExists("MyFile")
  ```
  (2) 인수를 변환해 반환하는 경우
  ```
  InputStream fileOpen("MyFile")
  ```
  (3) 이벤트 형식
  ```
  보통 입력 인수만 존재. 단, 이벤트임이 코드에 분명히 나타나야 함.
  특히, 변환함수에서 출력함수만 사용시 혼란야기 => 변환결과는 반환값으로 돌려주기!
  ex) void includeSetupPageInto(StringBuffer pageText) -> StringBuffer transform(String pageText)
  ```
 - 플래그 인수: 좋지 않다. 플래그를 인수로 넘기지 않도록 한다. (함수 쪼개기)
 - 이항 함수: 일부의 경우를 제외하곤 단항보다 이해하기 어렵다 => 단항 함수로 바꿀 수 있다
  (1) 한 값을 표현하는 두 요소들
  (2) 순서가 중요한 요소들
  ```
  ex) Point p = new Point(0,1)
  ```
 - 삼항 함수: (좌항,기준,우항)으로 비교목적일 땐 가치가 있으나 복잡도가 너무 높아짐
 ```
 ex) String.format
 ```
 
 ### To solve...
1. 인수 객체: 인수가 2~3개인 경우
 - 독자적인 클래스 변수로 선언!
2. 인수 목록: 인수가 가변적인 경우
 - 각각을 단항, 이항, 삼항 .. 함수로 취급 ( 그 이상은 문제 발생 여지가 있음)
3. 동사 및 키워드
 - 동사 : 함수이름
 - 명사 : 인자 이름
 - 함수 이름 : 이름에 인수들의 이름을 추가하여 인수 순서를 기억할 필요도를 줄이고, 정확성을 높이도록 함
4. 부수 효과를 일으키지 마라
 - 
5. 출력인수는 피하라
 - 객체지향의 this를 적절히 활용하여 주체와 대상을 구분하라
  (인수는 함수의 입력이 아니며 출력인수 또한 반환값이 아니다)
6. 명령과 조회를 분리하라
 - 객체 상태를 변경(변경수행) 또는 객체정보 반환(응답) 둘 중 한개만 수행하라!
7. 오류코드보다 예외를 사용하라
 - 오류코드 객체를 만들지 말고, try-catch를 사용하라
 - 명령함수에서 오류코드를 반환하는 것은 명령/조회 분리규칙을 미묘하게 만든다
 ```
 좋지 않은 예:
  if(deletePage(page)==E_OK){
   //...
  }
  
 더 좋은 예:
  public void delete(Page page){
     try{
       deletePageAndAllReference(pages);
     }catch(Exception e){
       logError(e);
     }
  }
 ```
8.오류 처리도 한가지 작업이다
 - 함수에 키워드 try가 있다면, try문으로 시작해 catch/finally 문으로 끝나야 함
9. 구조적 프로그래밍
 - 함수는 return 문이 하나여야 함
 - 루프안에 break, continue 사용 NO(작은 함수안에선 어느정도 허용), goto는 절대 안됨(작은 함수일때 특히!)


 ### 그래서 함수를 짜는 방법은?
  ***초안작성->단위 테스트 케이스로 만듬->다듬고, 이름을바꾸고, 중복제거 -> 메서드를 줄이고 순서를 바꾸거나 클래스를 쪼갬*** 
  단, 모두 단위 Test를 통과하여야 한다