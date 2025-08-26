import numpy as np

class ConvBase:
    def __init__(self, src):
      self.src = src
      self.ext = ".oops.txt"

    def lireSrc(self):
      return np.fromfile(self.src, dtype=np.int, sep='\n')

    def newName(self):
      return self.src + self.ext

    def conv(self):
      raise NotImplementedError()
    
    def conv():
      pass

####################################
# number = np.base_repr(x, base=2)
class ConvBin(ConvBase):

  def __init__(self, src):
    super.__init__(src)
    self.ext = ". bin . txt "

  def conv(self):
    values = super.lireSrc()

    with open(super.newName(), "w") as myfile:
      for x in values:
        myfile.write(f"{x:010b}\n")

         

####################################
# number = np.base_repr(x, base=16)
class ConvHexShift(ConvBase):

  def __init__(self, src):
    super.__init__(src)
    self.ext = ". hex . txt "

  def lireSrc(self):
    temp = super.lireSrc()
    temp = [x * 16 for x in temp]
    return temp

  def conv(self):
    values = super.lireSrc()

    with open(super.newName(), "w") as myfile:
      for x in values:
        myfile.write(hex(x) + "\n")


# Main
TestBin = ConvBin("sequenceChiffres.txt")
TestBin.conv()
TestHex = ConvHexShift("sequenceChiffres.txt")
TestHex.conv()