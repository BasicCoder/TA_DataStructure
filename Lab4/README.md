# Experiment 4
## 一.IP地址
### Problem Description
给定一个仅由数字组成的字符串，从中按顺序取出四个数字，组成一个合法的IPv4的地址，列出所有可能的组合。
IPv4地址由四个[0, 255]内的整数组成，以点’.’作为分隔符。
### Input
"25525512211"
### Ouput
“255.255.12.211”, “255.255.122.11”

## 二.最小修改距离
### Problem Description
给定两个字符串，s1、s2，找出最少的修改步数，使得两个字符串成为相同的字符串，每一步定义为在一个字符串中修改一个字符。
### Input
“about”, “above”
### Ouput
2（将”above”中的v修改为u，e修改为t）

### Hints
[Reference](https://people.cs.pitt.edu/~kirk/cs1501/Pruhs/Spring2006/assignments/editdistance/Levenshtein%20Distance.htm)