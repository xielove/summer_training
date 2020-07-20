# -*- coding:UTF-8 -*-

## 获取南京师范大学2020年暑假校队训练所有的题目信息，
## 并将每道题目的描述，格式，输入...等信息存放在md文件中
import requests
from bs4 import BeautifulSoup
import tomd
import os

target = "https://vijos.org/d/nnu_contest/training/5f0847d6f4136222859674b3"
prefix = "https://vijos.org"
headers = {
    'User-Agent': "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.163 Safari/537.36",
    'Cookie': "save=1; sid=643ede372f7e5d45471500c41a32996d18c8d7c9ea1f01f614e1e89831ab2399"
}

## 获取网页，并使用BeautifulSoup解析
def get_page(url: str, headers: dict) -> BeautifulSoup:
    session = requests.Session();
    req = session.get(url=url, headers=headers);
    html = req.text;
    bs = BeautifulSoup(html);
    return bs

## 获取索引信息列表，
## {
##  "href": "/d/nnu_contest/p/1153",
##  "name": "P1153 记数问题"
## }
def get_index() -> list:
    bs = get_page(target, headers)
    ## 所有的题目链接存放在<a href="...">name</a>
    ## 但是该标签并不全部是题目链接，需要进一步过滤
    ## 这里是直接尝试发现目标存在于href[4:-16]中，扩展性不好
    href = bs.find_all('a', class_='')
    href = href[4:-16]
    index = []
    for tag in href:
        index.append({'href': tag['href'], 'name': tag.string.strip()})
    return index

if __name__ == "__main__":
    index = get_index()
    for item in index:
        bs = get_page(prefix+item['href'], headers)
        problem = bs.find('div', class_="problem-content")
        dirname = item['name'].replace(' ', '_')
        if not os.path.exists(dirname):
            os.makedirs(dirname)
        ## 将Html代码片段转换成MarkDown文件
        with open(dirname+os.sep+"README.md", 'w') as f:
            f.write(tomd.convert(str(problem)))
            # title = problem.find_all('h1')[1:-1]
            # print('#', item['name'])
            # for s in problem.stripped_strings:
                # f.write(s+'\n')


