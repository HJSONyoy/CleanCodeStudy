## 목차  
- 작게 만들어라!  
	- 블록과 들여쓰기  
- 한 가지만 해라!  
	- 함수 내 섹션  
- 함수 당 추상화 수준은 하나로!  
	- 위에서 아래로 코드 읽기 : 내려가기 규칙  
- Switch문  
- 서술적인 이름을 사용하라!  
- 함수 인수  
	- 많이 쓰는 단항 형식  
	- 플래그 인수  
	- 이항 함수  
	- 삼항 함수  
	- 인수 객체  
	- 인수 목록  
	- 동사와 키워드  
- 부수 효과를 일으키지 마라!  
	- 출력 인수  
- 명령과 조회를 분리하라!  
- 오류코드보다 예외를 사용하라!  
	- Try/Catch 블록 뽑아내기  
	- 오류  처리도 한 가지 직업이다  
	- Error.java의 의존성 자석  
- 반복하지마라!  
- 구조적 프로그래밍  
- 함수를 어떻게 짜죠? 

##

'''java
public static String testableHtml(PageData pageData, boolean includeSuiteSetup) throws Exception { Wikipage wikipage = pageData.getWikiPage(); StringBuffer buffer = new StringBuffer(); if (pageData.hasAttribute("Test")) { if (includeSuiteSetup) { WikiPage suiteSetup = PageCrawlerlmpl.getlnheritedPage( SuiteResponder.SUITE_SETUP_NAME, wikiPage); if (suiteSetup != null) { wikiPagePath pagePath = suiteSetup.getPageCrawler().getFullPath(suiteSetup); String pagePathName = PathParser.render(pagePath); buffer.append("include -setup .") .append(pagePathName) .append("\n"); } } WikiPage setup = PageCrawlerlmpl.getInheritedPage("SetUp", wikiPage); if (setup != null) { WikiPagePath setupPath = wikiPage.getPageCrawler().getFullPath(setup); String setupPathName = PathParser.render(setupPath); buffer.append("!include -setup .") .append(setupPathName) .append("\n"); } } buffer.append(pageData.getContent()); if (pageData.hasAttribute("Test")) { WikiPage teardown = pageCrawlerlmpl.getInheritedPage("TearDown", wikiPage); if (teardown != null) { WikiPagePath tearDownPath = wikiPage.getPageCrawler().getFullPath(teardown); String tearDownPathName = PathParser.render(tearDownPath); buffer.append("\n") .append("!include -teardown .") .append(tearDownPathName) .append("\n"); } if (includeSuiteSetup) { WikiPage suiteTeardown = PageCrawlerlmpl.getlnheritedPage( SuiteResponder.SUITE_TEARDOWN_NAME, wikiPage ); if (suiteTeardown != null) { Wikipagepath pagePath = suiteTeardown.getPageCrawler().getFullPath (suiteTeardown); String pagePathName = PathParser.render(pagePath); buffer.append("!include -teardown .") .append(pagePathName) .append("\n"); } } } pageData.setContent(buffer.toString()); return pageData.getHtml(); }
'''

