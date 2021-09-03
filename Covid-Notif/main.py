# Written By Hydrolyzed~ (https://github.com/mastericez)
# Data Provider : https://github.com/djay/covidthailand
# Icon Provider : Flaticon
from datetime import date
import time
from plyer import notification
import requests

Covid = None
try:
    Covid = requests.get('https://raw.githubusercontent.com/wiki/djay/covidthailand/cases_briefings')
except:
    print("NULL")

used = "NO";

if Covid != None:
    data = Covid.json()
    while True:
        now = str(date.today())
        if now != used and now == data[-1]['Date']:
            cases = data[-1]
            title = 'Covid19 Stats {}'.format(now)
            message = 'Cases: {case}\nDeaths: {death}'.format(
                case = str(int(cases['Cases'])),
                death = str(int(cases['Deaths']))
            )
            notification.notify(
                title=title,
                message=message,
                app_icon="favico.ico",
                timeout=10,
                toast=False
            )
            used = now
            time.sleep(3*60*60)
