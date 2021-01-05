import discord
import os
import random
from replit import db
from runner import alive
import requests
import json
# from discord.ext import commands
# from discord.ext.commands import Bot

client = discord.Client()

def get_anime():
  res = requests.get("https://animechanapi.xyz/api/quotes/random")
  dat = json.loads(res.text)# print(dat)# print(dat[2])
  return dat['data']

# bot = commands.Bot(command_prefix = '$', help_command = None)
def update_icy(icy_message):
  if "icy" in db.keys():
    ice = db["icy"]
    ice.append(icy_message)
    db["icy"] = ice
  else :
    db["icy"] = [icy_message]

def delete_icy(idx):
  ice = db["icy"]
  if len(ice) > idx:
    del ice[idx]
  db["icy"] = ice

ls = ['ตกนรกไป', 'ซาหวัดดีค้าบบบบ', 'ไอเชี่ยนี่']

greet = [
  "ซาหวัดดีค้าบบบบ",  
  "จ๊ะเอ๋ตัวเอง", 
  "สวัสดีครับท่านผู้เจริญ"
  ]

hew = [
  "กินตีนกูมาไอสัส",
  "หิวแดกข้าวห้าวแดกตีน",
  "น้ำพึ่งเรือ เสือพึ่งป่า อัชฌาสัย"
]

command_list = "```Command List\n $q or $quote for Quotes\n $add [Quote] for add Quote \n $remove [Index of Quote] for remove Quote\n $list for List of Quotes]\n $fixed for Fixed Quotes\n $anime for anime quote\n $greet for Greetings\n $กินไรดี for asking what should you eat```"
'''
bot = commands.Bot(command_prefix = ('$'), description = 'Hi')

@ bot.event
async def on_ready():
    print('Icy : {0.user}666-'.format(client))
activity = discord.Game(name = 'Free Fire', type = 3)
await bot.change_presence(status = discord.Status.idle, activity = activity)
'''

@client.event 
async def on_ready():
  print('Icy : {0.user}666-'.format(client))
  await client.change_presence(activity = discord.Streaming(name = 'Free Fire', url = 'https://www.twitch.tv/directory/game/Garena%20Free%20Fire'))

@client.event
async def on_message(msg):
  if msg.author == client.user:
    return
  if msg.content == '$anime':
    q = get_anime()
    ans = q[0]['quote'] + "\n -" + q[0]['character'] + " [" + q[0]['anime'] + "]"
    await msg.channel.send(ans)
  if msg.content == '$help':
    await msg.channel.send(command_list)
  options = ls
  if "icy" in db.keys():
    options = options + db["icy"]
  if msg.content == '$quote':
  	icy = random.choice((options))
  	await msg.channel.send(icy)
  if msg.content == '$q':
    icy = random.choice((options))
    await msg.channel.send(icy)
  if msg.content.startswith('$add'):
    icy_message = msg.content.split('$add ', 1)[1]
    update_icy(icy_message)
    await msg.channel.send("Added Success!~")
  if msg.content.startswith('$remove'):
    icy_msg = []
    if "icy" in db.keys():
      idx = int(msg.content.split('$remove', 1)[1])
      delete_icy(idx)
      icy_msg = db["icy"]
      await msg.channel.send(icy_msg)
  if msg.content == '$list':
    icy = []
    if "icy" in db.keys():
      icy = db["icy"]
    await msg.channel.send(icy)
  if msg.content.startswith('$fixed'):
    idx = int(msg.content.split('$fixed', 1)[1])
    if idx > len(db["icy"]) :
      await msg.channel.send("ไม่มีโว้ย จะส่งมาทำเหี้ยไร")
      return
    await msg.channel.send(db["icy"][idx - 1])
  if msg.content == '$greet' :
    await msg.channel.send(random.choice(greet))
  if msg.content == "$กินไรดี" :
    await msg.channel.send(random.choice(hew))



'''
bot = Bot(command_prefix = '$')

@bot.event
async def on_ready():
  print('Icy : {0.user}666-'.format(client))
  await bot.change_presence(activity = discord.Game('Free Fire'))
'''
alive()

client.run(os.getenv('TOKEN'))
