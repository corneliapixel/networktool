def show_menu():
    print('=== NÄTVERKSVERKTYG ===')
    print('1. Validera IP-adress')
    print('2. Validera port')
    print('3. Visa logg')
    print('4. Avsluta.')


    while True: 
         show_menu()
         choice = input('Gör ett val (1-4): ')
         
         # Choice 1 - Validera IP-adress: följer formatet x.x.x.x där varje oktett är ett heltal mellan 0 och 255. 
    if choice == '1': 
        ip = input('Ange IP-adress: ')
        octets = ip.split(".")
        if len(octets) == 4 and all(0 <= int(octet) <= 255 for octet in octets):
            print(ip + ' är en giltig IP-adress.')
        else: 
            print(ip + ' är en ogiltig IP-adress.')

    # Choice 2 - Validerar port (giltig/ogiltig)

    if choice == '2':
         port = input('Ange port: ')
         if port.isdigit ():
              port = int(port)
              if 1 <= port <= 65535:
                   print(str(port) + ' är en giltig port!')  
                   print(str(port) + ' är en ogiltig port.')  
              else:
                   print('Input är ogiltig! Försök igen med ett nummer! :)')

    # Choice 3 - Visa loggen: 
    import logging

    logging.basicConfig(
         level=logging.INFO,
         format='%(asctime)s - %(levelname)s - %(message)s',
         datefmt='%Y-%m-%d %H:%M:%S'
    )

    logg = []

    if choice == '3':
         print('Logg:')
         for rad in logg:
              print(rad)
                   
    # Choice 4 - Avslutar programmet
    elif choice == '4':
            print('Avslutar...')
            break
    