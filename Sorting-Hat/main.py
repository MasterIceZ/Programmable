import discord
from discord.ext import commands
import os
import asyncio
import random
from runner import alive

token = os.getenv('TOKEN')

intents = discord.Intents.default()
intents.members = True
client = commands.Bot(command_prefix = "?", intents = intents)

hu = [
	'Gryffindor',
	'Ravenclaw',
	'Hufflepuff',
	'Slytherin'
]

@client.event
async def on_ready() :
	print("Hello Ice")

@client.event
async def on_member_join(member):
	print('ok')
	rl = random.choice(hu)
	role = discord.utils.get(member.guild.roles, name=rl)
	await member.add_roles(role)

alive()
client.run(token)
