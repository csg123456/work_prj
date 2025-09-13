# git常用指令

## 0. git工作原理
1. 三个区域：工作区 (working tree)、暂存区/索引 (index / staging area)、本地仓库 (.git/object 等)。

2. 对象模型：所有内容都以对象保存 —— blob（文件内容）、tree（目录）、commit（快照 + 元数据）、tag（可选签名）。每个对象通过 SHA-1/sha256 哈希唯一标识。

3. 提交与快照：commit 指向一个 tree（表示整个项目某一时刻的文件树），并记录父 commit、作者、提交信息。Git 保存的是快照而非差异（内部通过对象去重实现高效）。

4. HEAD 与 refs：HEAD 指向当前检出的分支引用（如 refs/heads/main）或某个具体 commit（detached HEAD）。分支只是指向 commit 的可移动引用。

5. 索引的作用：你修改文件后用 git add 把文件状态写入索引，最终 git commit 用索引内容创建新的 commit。

6. 远程与同步：远程只是引用的集合（refs），git fetch 获取远程引用和对象到本地，git push 把本地引用推送到远程。git pull = fetch + merge（或 rebase，取决配置）。

## 1. git clone
1. 作用：拷贝远程仓库到本地（含所有历史、默认创建远程名 origin）。
2. 示例：git clone https://host/repo.git
3. 注意：可用 --depth 做浅克隆；会创建本地 origin remote。

## 2. git checkout
1. 作用：切换分支或检出某个 commit/文件；（新版本推荐 git switch/git restore 做更细的动作）。
2. 示例：git checkout feature  // 若本地不存在但 origin/feature 存在，较新 Git 会创建并关联; git checkout -b feature (创建并切换)
3. 注意：若有未提交修改，切换可能被阻止或导致工作树覆盖（先 stash 或 commit）。

## 3. git branch

## 4. git fetch

## 5. git merge

## 6. git push

## 7. git pull

## 8. git add

## 9. git commit

## 10. git stash

## 11. git stash pop

## 12. origin

## 13. git fork

## 14. git remote

## 15. git status