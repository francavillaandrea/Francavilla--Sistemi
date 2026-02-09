#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

// Player represents a single football player
typedef struct
{
  // The player name
  char *name;

  // The number of the player
  int number;
} Player;

/**
 * createPlayer creates a valid Player entity.
 *
 * @param name The name of the player, must not be empty or NULL
 * @param number The number of the player, must be > 0-
 *
 * @returns The valid player, or NULL in case of any error
 */
Player *createPlayer(char *name, int number)
{
  if (name == NULL || strlen(name) == 0 || number <= 0)
  {
    return NULL;
  }

  Player *player = (Player *)malloc(sizeof(Player));
  player->name = (char *)malloc(strlen(name) + 1);
  strcpy(player->name, name);
  player->number = number;

  return player;
}

/**
 * clonePlayer creates a valid Player entity by copying another one.
 *
 * @param player The player to clone, must not be NULL
 *
 * @returns The cloned player, or NULL in case of any error
 */
Player *clonePlayer(Player *player)
{
  if (player == NULL)
  {
    return NULL;
  }

  return createPlayer(player->name, player->number);
}

/**
 * destroyPlayer destroys a previously created Player entity and deallocates
 * it completely.
 *
 * @param player The player to destroy, must not be NULL
 *
 * @returns -1 in case of any error, 0 otherwise
 */
int destroyPlayer(Player *player)
{
  if (player == NULL)
  {
    return -1;
  }

  free(player->name);
  free(player);
  return 0;
}

/**
 * serializePlayer serializes the player into the specified file.
 *
 * @param player The player to serialize, must not be NULL
 * @param out_file The output file to serialize into, must not be NULL
 *
 * @returns -1 in case of any error, 0 otherwise
 */
int serializePlayer(Player *player, FILE *out_file)
{
  if (player == NULL || out_file == NULL)
  {
    return -1;
  }

  fprintf(out_file, "%s %d", player->name, player->number);
  return 0;
}

/**
 * deserializePlayer deserializes the player from the specified file.
 *
 * @param in_file The output file to deserialize from, must not be NULL
 *
 * @returns The deserialized player, or NULL in case of any error
 */
Player *deserializePlayer(FILE *in_file)
{
  if (in_file == NULL)
  {
    return NULL;
  }

  char name[MAX_LENGTH];
  int number;

  if (fscanf(in_file, "%s %d", name, &number) != 2)
  {
    return NULL;
  }

  return createPlayer(name, number);
}

// Team represents a football team
typedef struct
{
  // The name of the team
  char *name;

  // The array of members of the team
  Player *members;

  // The team members count
  int members_count;
} Team;

/**
 * createTeam creates a valid Team entity.
 *
 * @param name The name of the team, must not be empty or NULL
 * @param members The array of members, must not be NULL
 * @param members_count The number of the members of the team, must be > 0
 *
 * @returns The valid team, or NULL in case of any error
 */
Team *createTeam(char *name, Player *members, int members_count)
{
  if (name == NULL || strlen(name) == 0 || members == NULL || members_count <= 0)
  {
    return NULL;
  }

  Team *team = (Team *)malloc(sizeof(Team));
  team->name = (char *)malloc(strlen(name) + 1);
  strcpy(team->name, name);

  team->members = (Player *)malloc(sizeof(Player) * members_count);
  for (int i = 0; i < members_count; i++)
  {
    team->members[i].name = (char *)malloc(strlen(members[i].name) + 1);
    strcpy(team->members[i].name, members[i].name);
    team->members[i].number = members[i].number;
  }

  team->members_count = members_count;
  return team;
}

/**
 * cloneTeam creates a valid Team entity by copying another one.
 *
 * @param team The team to clone, must not be NULL
 *
 * @returns The cloned team, or NULL in case of any error
 */
Team *cloneTeam(Team *team)
{
  if (team == NULL)
  {
    return NULL;
  }

  return createTeam(team->name, team->members, team->members_count);
}

/**
 * destroyTeam destroys a previously created Team entity and deallocates
 * it completely.
 *
 * @param team The team to destroy, must not be NULL
 *
 * @returns -1 in case of any error, 0 otherwise
 */
int destroyTeam(Team *team)
{
  if (team == NULL)
  {
    return -1;
  }

  for (int i = 0; i < team->members_count; i++)
  {
    free(team->members[i].name);
  }

  free(team->members);
  free(team->name);
  free(team);
  return 0;
}

/**
 * serializeTeam serializes the team into the specified file.
 *
 * @param team The team to serialize, must not be NULL
 * @param out_file The output file to serialize into, must not be NULL
 *
 * @returns -1 in case of any error, 0 otherwise
 */
int serializeTeam(Team *team, FILE *out_file)
{
  if (team == NULL || out_file == NULL)
  {
    return -1;
  }

  fprintf(out_file, "%s %d\n", team->name, team->members_count);

  for (int i = 0; i < team->members_count; i++)
  {
    if (serializePlayer(&team->members[i], out_file) == -1)
    {
      return -1;
    }
    fprintf(out_file, "\n");
  }

  return 0;
}

/**
 * deserializeTeam deserializes the team from the specified file.
 *
 * @param in_file The output file to deserialize from, must not be NULL
 *
 * @returns The deserialized team, or NULL in case of any error
 */
Team *deserializeTeam(FILE *in_file)
{
  if (in_file == NULL)
  {
    return NULL;
  }

  char name[MAX_LENGTH];
  int members_count;

  if (fscanf(in_file, "%s %d\n", name, &members_count) != 2)
  {
    return NULL;
  }

  Player *members = (Player *)malloc(sizeof(Player) * members_count);
  for (int i = 0; i < members_count; i++)
  {
    Player *player = deserializePlayer(in_file);
    if (player == NULL)
    {
      for (int j = 0; j < i; j++)
      {
        free(members[j].name);
      }
      free(members);
      return NULL;
    }
    members[i] = *player;
    free(player);
  }

  Team *team = createTeam(name, members, members_count);

  for (int i = 0; i < members_count; i++)
  {
    free(members[i].name);
  }
  free(members);

  return team;
}