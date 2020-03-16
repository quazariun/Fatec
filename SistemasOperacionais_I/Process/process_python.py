import os // Importo a biblioteca

def child():
   print('\nUm novo processo filho ',  os.getpid())
   subprocess.Popen(['C:\Program Files\Mozilla Firefox\\firefox.exe', '-new-tab']) # Abro o Firefox no processo filho
   os._exit(0) # Fecho o processo

def parent():

   # coloco um while(true) para poder testar várias vezes
   while True:
      newpid = os.fork() # Fork semelhante ao do linux

      # Note que a estrutura é muito parecida com a do Linux
      if newpid == 0:
         child()
      else:
         pids = (os.getpid(), newpid)
         print("parent: %d, child: %d\n" % pids)
      # Aqui eu continuo o loop
      reply = input("q para sair / c para um novo Fork()")
      if reply == 'c': 
          continue
      else:
          break

parent()