class test:
    def __init__(self):
        self.data=[]
    def add(self, value):
        self.data.append(value)
    def get(self):
        return self.data
    def clear(self):
        self.data = []
    
def main():
    t = test()
    t.add(1)
    t.add(2)
    t.add(3)
    print(t.get())  # Output: [1, 2, 3]
    t.clear()
    print(t.get())  # Output: []
    
if __name__ == "__main__":
    main()