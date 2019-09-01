# import datetime
# print(datetime.datetime.now().strftime('%Y-%m-%d'))

import time
now = time.localtime()
print('%04d-%02d-%02d' %(now.tm_year, now.tm_mon, now.tm_mday)) 