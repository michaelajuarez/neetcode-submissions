class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()    

    def addWord(self, word: str) -> None:
        current = self.root
        for x in word:
            if x not in current.children:
                current.children[x] = TrieNode()
            current = current.children[x]
        current.end = True

    def search(self, word: str) -> bool:
        def dfs(index, root):
            current = root

            for i in range(index, len(word)):
                if word[i] == '.':
                    for x in current.children.values():
                        if (dfs(i+1, x)):
                            return True
                    return False
                else:
                    if word[i] not in current.children:
                        return False
                    current = current.children[word[i]]
            return current.end
        return dfs(0, self.root)

        